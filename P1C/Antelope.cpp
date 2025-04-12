#include "Headers.h"

Antelope::Antelope()
    : Animal{ 2 , 4 }
{


}

void Antelope::action()
{
	std::vector<Cell*> neighbours;
    int offsets[8][2] = { { -1, 0} , { 1,0 }, {0,-1 }, {0,1}, { -2, 0} , { 2,0 }, {0,-2 }, {0,2} };

	for (int i = 0; i < 8; i++)
	{
		int r = m_position->getRow() + offsets[i][0];
		int c = m_position->getColumn() + offsets[i][1];
		/*
		int r = m_position->m_row + offsets[i][0];
		int c = m_position->m_column + offsets[i][1];*/
		Cell* neighbour = m_world->getCellOrNull(r, c);
		if (neighbour != nullptr)
		{
			neighbours.push_back(neighbour);
		}
	}

	int a = rand() % neighbours.size();
	m_world->moveTo(this, neighbours[a]);
}

void Antelope::print()
{
    std::cout << "A";
}

bool Antelope::escapeAttack()
{
	std::vector<Cell*> neighbours;
	int offsets[4][2] = { { -1, 0} , { 1,0 }, {0,-1 }, {0,1}};

	for (int i = 0; i < 4; i++)
	{
		int r = m_position->getRow() + offsets[i][0];
		int c = m_position->getColumn() + offsets[i][1];

		/*
		int r = m_position->m_row + offsets[i][0];
		int c = m_position->m_column + offsets[i][1];*/
		Cell* neighbour = m_world->getCellOrNull(r, c);
		if (neighbour != nullptr && neighbour->getOrganism() == nullptr)
		{
			neighbours.push_back(neighbour);
		}
	}
	if (neighbours.size() != 0)
	{
		int a = rand() % neighbours.size();
		m_world->moveTo(this, neighbours[a]);
		return true;
	}
	return false;
}

std::string Antelope::getSpecies() const
{
	return "Antelope";
}

Antelope* Antelope::clone() const
{
	return new Antelope;
}