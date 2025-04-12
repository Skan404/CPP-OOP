#include "Headers.h"
#include <algorithm>


World::World(int width, int height, int humanR, int humanC)
{
	start(width, height, humanR, humanC, 5, 0, 0);

}

void World::addOrganism(Organism* o, int row, int column)
{
	Cell* position = &m_cells[row][column];
	if (position->getOrganism() != nullptr)
	{
		throw 0;
	}
	m_organisms.push_back(o);
	m_cells[row][column].m_organisms.push_back(o);
	o->m_position = &m_cells[row][column];
	o->m_world = this;
	o->m_birthday = m_turn;
}

void World::printWorld()
{
	std::cout << std::endl;
	for (int r = 0; r < m_height; r++)
	{
		for (int c = 0; c < m_width; c++)
		{
			Cell& cell = m_cells[r][c];
			if (cell.m_organisms.size() == 0)
			{
				std::cout << ".";

			}
			else if (cell.m_organisms.size() == 1)
			{
				cell.m_organisms[0]->print();
			}
			else
			{
				std::cout << cell.m_organisms.size();
			}
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;
}

void World::getNeighbours(Cell* position, std::vector<Cell*>& neighbours)
{
	int offsets[4][2] = { { -1, 0} , { 1,0 }, {0,-1 }, {0,1} };

	for (int i = 0; i < 4; i++)
	{
		int r = position->getRow() + offsets[i][0];
		int c = position->getColumn() + offsets[i][1];
		Cell* neighbour = getCellOrNull(r, c);
		if (neighbour != nullptr)
		{
			neighbours.push_back(neighbour);
		}
	}
}

Cell* World::getCellOrNull(int row, int column)
{
	if (row >= m_height || row < 0)
	{
		return nullptr;
	}
	else if (column >= m_width || column < 0)
	{
		return nullptr;
	}

	return &m_cells[row][column];
}

void World::moveTo(Organism* o, Cell* position)
{
	Organism* occupant = position->getOrganism();
	if (occupant == nullptr)
	{
		moveToEmptyCell(o, position);
	}
	else
	{
		std::cout << "Kolizja pomiedzy " << o->getSpecies() << " " << occupant->getSpecies() << std::endl;
		switch (o->collision(occupant))
		{
		case CollisionResult::REPEL:
		{
			std::cout << o->getSpecies() << " odstrasza " << occupant->getSpecies() << std::endl;
			std::vector<Cell*> emptyNeighbours;
			getNeighboursWithoutOrganism(occupant->m_position, emptyNeighbours);

			if (emptyNeighbours.size() == 0)
			{
				int a = rand() % emptyNeighbours.size();
				moveTo(o, emptyNeighbours[a]);
			}
			break;
		}
		case CollisionResult::KILLS:
			kill(occupant);
			moveToEmptyCell(o, position);
			std::cout << o->getSpecies() << " zabija " << occupant->getSpecies() << std::endl;
			break;
		case CollisionResult::DIES:
			kill(o);
			std::cout << occupant->getSpecies() << " zabija " << o->getSpecies() << std::endl;
			break;
		case CollisionResult::DIES_AND_KILLS:
			kill(o);
			kill(occupant);
			std::cout << o->getSpecies() << " zabija " << occupant->getSpecies() << " i sam ginie " << std::endl;
			break;
		case CollisionResult::RETURNS:
			std::cout << o->getSpecies() << " powraca na swoje miejsce " << std::endl;
			break;
		case CollisionResult::ESCAPED:
			std::cout << o->getSpecies() << " ucieka " << std::endl;
			break;
		case CollisionResult::BREED:
			std::cout << o->getSpecies() << " rozmnozyl sie " << std::endl;
			break;
		}
	}
}

void World::action()
{
	m_turn++;
	std::vector<Organism*> o = m_organisms;
	
	class Less
	{
	public:
		bool operator()(Organism* a, Organism* b) const
		{
			if (a->getInitiative() > b->getInitiative())
			{
				return true;
			}
			if (a->getInitiative() < b->getInitiative())
			{
				return false;
			}
			return a->getAge() > b->getAge();
		}
	};

	std::sort(o.begin(), o.end(), Less{});
	
	for (int i = 0; i < o.size(); i++)
	{
		if (o[i]->m_destroyed == true)
			continue;

		o[i]->action();
	}

	for (int i = 0; i < m_organisms.size(); )
	{
		if (m_organisms[i]->m_destroyed == true)
		{
			if (m_organisms[i] == m_human) // umieranie czlowieka - konczenie gry
			{
				m_human = nullptr;
			}
			delete m_organisms[i];
			m_organisms.erase(m_organisms.begin() + i);

		}
		else
		{
			i++;
		}
	}
	
}

Human* World::getHuman()
{
	return m_human;
}

int World::getHumanDirectionR() const
{
	return m_humanDirectionR;
}

int World::getHumanDirectionC() const
{
	return m_humanDirectionC;
}

void World::setHumanDirection(int directionR, int directionC)
{
	m_humanDirectionR = directionR;
	m_humanDirectionC = directionC;
}

int World::getTurn() const
{
	return m_turn;
}

void World::kill(Organism* o)
{
	std::cout << o->getSpecies() << " zostaje zabity na pozycji row: " << o->getPosition()->getRow() << " column: " << o->getPosition()->getColumn() << std::endl;
	o->m_destroyed = true;
	for (int i = 0; i < o->m_position->m_organisms.size(); i++)
	{
		if (o->m_position->m_organisms[i] == o)
		{
			o->m_position->m_organisms.erase(o->m_position->m_organisms.begin() + i);
			o->m_position = nullptr;
			break;
		}
	}
}

void World::moveToEmptyCell(Organism* o, Cell* position)
{
	o->m_position->m_organisms.erase(std::find(o->m_position->m_organisms.begin(), o->m_position->m_organisms.end(), o));
	position->m_organisms.push_back(o);
	o->m_position = position;
}

void World::getNeighboursWithoutOrganism(Cell* position, std::vector<Cell*>& neighbours)
{
	int offsets[4][2] = { { -1, 0} , { 1,0 }, {0,-1 }, {0,1} };

	for (int i = 0; i < 4; i++)
	{
		int r = position->getRow() + offsets[i][0];
		int c = position->getColumn() + offsets[i][1];
		/*
		int r = position->m_row + offsets[i][0];
		int c = position->m_column + offsets[i][1];*/
		Cell* neighbour = getCellOrNull(r, c);
		if (neighbour != nullptr && neighbour->getOrganism() == nullptr)
		{
			neighbours.push_back(neighbour);
		}
	}
}

void World::printInformations()
{
	std::cout << "Szymon Kaniewski, 193423" << std::endl;
	if (getHuman()->getspecialAbilityRemaining() != 0)
	{
		std::cout << "Pozostala dlugosc spejcalnej umiejetnosci: " << getHuman()->getspecialAbilityRemaining() << " tur " << std::endl;
		std::cout << "Sila czlowieka: " << getHuman()->getStrength() << std::endl;
	}
	else if (getHuman()->getspecialAbilityPauseRemaining() != 0)
	{
		std::cout << "Pozostala pauza specjalnej umiejetnosci: " << getHuman()->getspecialAbilityPauseRemaining() << " tur " << std::endl;
		std::cout << "Sila czlowieka: " << getHuman()->getStrength() << std::endl;
	}
	else
	{
		std::cout << "Specjalna umiejetnosc jest gotowa " << std::endl;
		std::cout << "Sila czlowieka: " << getHuman()->getStrength() << std::endl;
	}
}

bool World::isGameFinished() const
{
	if (m_human != nullptr)
	{
		return false;
	}
	return true;
}

void World::start(int width, int height, int humanR, int humanC, int strength, int specialAbilityRemaning, int specialAbilityPauseRemaning)
{
	m_width = width;
	m_height = height;
	m_human = new Human{strength, specialAbilityRemaning, specialAbilityPauseRemaning};
	m_turn = 0;
	m_cells.resize(m_height);

	for (int r = 0; r < m_cells.size(); r++)
	{
		m_cells[r].resize(m_width);
		for (int c = 0; c < m_width; c++)
		{
			m_cells[r][c].setColumn(c);
			m_cells[r][c].setRow(r);
			/*
			m_cells[r][c].m_column = c;
			m_cells[r][c].m_row = r;*/

		}
	}
	addOrganism(m_human, humanR, humanC);

}

void World::clear()
{
	for (int i = 0; i < m_organisms.size(); i++)
	{
		delete m_organisms[i];
	}
	m_organisms.clear();
	m_cells.clear();
	
}

void World::saveState(const std::string& path)
{
	std::ofstream file{ path };
	if (file.good())
	{
		file << m_height << " ";
		file << m_width << " ";
		file << m_turn << std::endl;
		file << m_human->getPosition()->getRow() << " " << m_human->getPosition()->getColumn() << " ";
		file << m_human->getStrength() << " ";
		file << m_human->getspecialAbilityRemaining() << " " << m_human->getspecialAbilityPauseRemaining() << std::endl;
		file << m_organisms.size() - 1 << std::endl;
		for (int i = 0; i < m_organisms.size(); i++)
		{
			Organism* o = m_organisms[i];
			if (o != m_human)
			{
				file << o->getSpecies() << " " << o->getPosition()->getRow() << " " << o->getPosition()->getColumn() << " " << o->m_strength << " " << o->m_birthday << std::endl;
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku do zapisu " << std::endl;
	}
}

void World::loadState(const std::string& path)
{
	std::ifstream file{ path };
	if (file.good())
	{
		clear();
		int height, width, turn, humanRow, humanColumn, humanStrength, humanSpecialAbilityRamining, humanSpecialAbilityPauseRemaining;
		file >> height >> width >> turn;
		file >> humanRow >> humanColumn >> humanStrength >> humanSpecialAbilityRamining >> humanSpecialAbilityPauseRemaining;
		start(width, height, humanRow, humanColumn, humanStrength, humanSpecialAbilityRamining, humanSpecialAbilityPauseRemaining);
		m_turn = turn;
		int organismsSize, oRow, oColumn, oStrength, oBirthday;
		file >> organismsSize;
		for (int i = 0; i < organismsSize; i++)
		{
			std::string species;
			file >> species >> oRow >> oColumn >> oStrength >> oBirthday;
			Organism* o = nullptr;
			if (species == "Antelope")
			{
				o = new Antelope;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Belladonna")
			{
				o = new Belladonna;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Fox")
			{
				o = new Fox;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Grass")
			{
				o = new Grass;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Guarana")
			{
				o = new Guarana;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Hogweed")
			{
				o = new Hogweed;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Milt")
			{
				o = new Milt;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Sheep")
			{
				o = new Sheep;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Turtle")
			{
				o = new Turtle;
				addOrganism(o, oRow, oColumn);
			}
			else if (species == "Wolf")
			{
				o = new Wolf;
				addOrganism(o, oRow, oColumn);
			}
			o->m_strength = oStrength;
			o->m_birthday = oBirthday;
		}
		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku do odczytu " << std::endl;
	}
}