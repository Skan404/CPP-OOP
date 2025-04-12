#include "Headers.h"

Milt::Milt()
    : Plant{ 0, 0, 0 }
{


}

void Milt::print()
{
    std::cout << "g";
}

Milt* Milt::clone() const
{
    return new Milt;
}

void Milt::breed() // rozmna¿a siê do pierwszej udanej próby
{
    std::vector<Cell*> neigbours;
    m_world->getNeighbours(m_position, neigbours);


    for (int i = 0; i < 3; i++)
    {
        int a = rand() % neigbours.size();

        if (neigbours[a]->getOrganism() == nullptr)
        {
            m_world->addOrganism(clone(), neigbours[a]->getRow(), neigbours[a]->getColumn());
            //m_world->addOrganism(clone(), neigbours[a]->m_row, neigbours[a]->m_column);
        }
    }
}

std::string Milt::getSpecies() const
{
    return "Milt";
}