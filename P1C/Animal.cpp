#include "Headers.h"

Animal::Animal(int strength, int initiative)
    : Organism{strength, initiative}
{
   
}

void Animal::action() //override - bedizemy napisywac
{
    std::vector<Cell*> neigbours;
    m_world->getNeighbours(m_position, neigbours);
    int a = rand() % neigbours.size();
    m_world->moveTo(this, neigbours[a]);

}

CollisionResult Animal::collision(Organism* o)
{
    if (o->isPlant())
    {
        Plant* p = static_cast<Plant*>(o);
        if (p->isPoisonous())
        {
            return CollisionResult::DIES_AND_KILLS;
        }
        else
        {
            m_strength += p->getNutritionValue();
            return CollisionResult::KILLS;
        }
    }
    else
    {
        Animal* a = static_cast<Animal*>(o); // rzutowanie
        if (a->getSpecies() != getSpecies())
        {
            if (a->isAttackCountered(this))
            {
                return CollisionResult::RETURNS;
            }
            else if (a->isAttackRepelled(this))
            {
                return CollisionResult::REPEL;
            }
            else if (a->escapeAttack())
            {
                return CollisionResult::ESCAPED;
            }
            else if (m_strength < a->getStrength())
            {
                return CollisionResult::DIES;
            }
            else
            {
                return CollisionResult::KILLS;
            }
        }
        else
        {
            std::vector<Cell*> neigbours;
            m_world->getNeighbours(m_position, neigbours);
            for (int i = 0; i < neigbours.size();)
            {
                if (neigbours[i]->getOrganism() != nullptr)
                {
                    neigbours.erase(neigbours.begin() + i);
                }
                else
                {
                    i++;
                }
            }
            if (neigbours.size() != 0)
            {
                int a = rand() % neigbours.size();
                m_world->addOrganism(clone(), neigbours[a]->getRow(), neigbours[a]->getColumn());
                //m_world->addOrganism(clone(), neigbours[a]->m_row, neigbours[a]->m_column);
                
            }
            return CollisionResult::BREED;
        }
    }

}

void Animal::print()
{
    std::cout << "a";
}

bool Animal::isPlant() const
{
    return false;
}

bool Animal::isAnimal() const
{
    return true;
}

bool Animal::isAttackCountered(Animal* a) const
{
    return false;
}

bool Animal::escapeAttack()
{
    return false;
}

bool Animal::isAttackRepelled(Animal* a) const
{
    return false;
}