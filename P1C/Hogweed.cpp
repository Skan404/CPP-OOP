#include "Headers.h"

Hogweed::Hogweed()
    : Plant{ 10, 0, 0 }
{


}

void Hogweed::print()
{
    std::cout << "h";
}

void Hogweed::action()
{
    Plant::action();

    std::vector<Cell*> neigbours;
    m_world->getNeighbours(m_position, neigbours);
    for (int i = 0; i < neigbours.size(); i++)
    {
        if (neigbours[i]->getOrganism() && neigbours[i]->getOrganism()->isAnimal())
        {
            std::cout << "Barszcz Sosnowskiego zabija " << neigbours[i]->getOrganism()->getSpecies() << " na pozycji row: " << neigbours[i]->getOrganism()->getPosition()->getRow() << " column: " << neigbours[i]->getOrganism()->getPosition()->getColumn() << std::endl;
            m_world->kill(neigbours[i]->getOrganism());
        }
    }
}

Hogweed* Hogweed::clone() const
{
    return new Hogweed;
}

bool Hogweed::isPoisonous() const
{
    return true;
}

std::string Hogweed::getSpecies() const
{
    return "Hogweed";
}