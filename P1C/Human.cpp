#include "Headers.h"


Human::Human(int strength, int specialAbilityRemaning, int specialAbilityPauseRemaning)
	: Animal{strength, 4}
{
	m_specialAbilityRemaining = specialAbilityRemaning;
	m_specialAbilityPauseRemaining = specialAbilityPauseRemaning;
}

void Human::action()
{
	int directionR = getWorld()->getHumanDirectionR();
	int directionC = getWorld()->getHumanDirectionC();
	/*
	int directionR = m_world->getHumanDirectionR();
	int directionC = m_world->getHumanDirectionC();*/
	if (directionR == 0 && directionC == 0)
	{
		return;
	}

	Cell* destination = getWorld()->getCellOrNull(getPosition()->getRow() + directionR, getPosition()->getColumn() + directionC);
	//Cell* destination = m_world->getCellOrNull(m_position->m_row + directionR, m_position->m_column + directionC);

	if (destination != nullptr)
	{
		getWorld()->moveTo(this, destination);
		//m_world->moveTo(this, destination);
	}

	if (m_specialAbilityRemaining != 0)
	{
		m_specialAbilityRemaining--;

		if (m_specialAbilityRemaining == 0)
		{
			m_specialAbilityPauseRemaining = 5;
		}
	}
	else if(m_specialAbilityPauseRemaining != 0)
	{
		m_specialAbilityPauseRemaining--;
	}
}


CollisionResult Human::collision(Organism* o)
{
	return Animal::collision(o);
}

void Human::print()
{
	std::cout << "H";
}

std::string Human::getSpecies() const
{
	return "Human";
}

bool Human::canActivateSpecialAbility() const
{
	if (m_specialAbilityPauseRemaining == 0 && m_specialAbilityRemaining == 0)
	{
		return true;
	}
	
	return false;
}

void Human::activateSpecialAbility()
{
	m_specialAbilityRemaining = 5;
}

bool Human::isAttackRepelled() const
{
	if (m_specialAbilityRemaining != 0)
		return true;
	else
		return false;

}

int Human::getspecialAbilityPauseRemaining()
{
	return m_specialAbilityPauseRemaining;
}

int Human::getspecialAbilityRemaining()
{
	return m_specialAbilityRemaining;
}