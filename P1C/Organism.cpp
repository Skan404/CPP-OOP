#include "Headers.h"

Organism::Organism(int strength, int initiative)
{
	m_strength = strength;
	m_initiative = initiative;
	m_destroyed = false;
}

int Organism::getStrength() const
{
	return m_strength;
}

int Organism::getInitiative() const
{
	return m_initiative;
}

Organism* Organism::clone() const
{

	return nullptr;
}

void Organism::action()
{

}
CollisionResult Organism::collision(Organism* o)
{
	throw std::exception("brak implementacji kolizji");
}
void Organism::print()
{
	std::cout << "o";
}

int Organism::getAge() const
{
	return m_world->getTurn() - m_birthday;
}

bool Organism::isAttackCountered(Organism* o) const
{
	return false;

}

World* Organism::getWorld() const 
{ 
	return m_world; 
}

void Organism::setWorld(World* world) 
{ 
	m_world = world; 
}

Cell* Organism::getPosition() const 
{ 
	return m_position; 
}

void Organism::setPosition(Cell* position) 
{ 
	m_position = position; 
}
