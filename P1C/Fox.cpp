#include "Headers.h"

Fox::Fox()
    : Animal{3 , 7}
{


}

void Fox::action()
{
    std::vector<Cell*> neigbours;
    m_world->getNeighbours(m_position, neigbours);
    for (int i = 0; i < neigbours.size(); )
    {
        Organism* o = neigbours[i]->getOrganism();
        if (o != nullptr && o->getStrength() > this->m_strength)
        {
            neigbours.erase(neigbours.begin() + i);
        }
        else
        {
            i++;
        }
    }
    if (neigbours.size() > 0)
    {
        int a = rand() % neigbours.size();
        m_world->moveTo(this, neigbours[a]);

    }
}

void Fox::print()
{
    std::cout << "F";
}

std::string Fox::getSpecies() const
{
    return "Fox";
}

Fox* Fox::clone() const
{
    return new Fox;
}