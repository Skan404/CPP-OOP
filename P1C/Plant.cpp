#include "Headers.h"

Plant::Plant(int strength, double probabilityOfCloning, int nutritionValue)
	: Organism{ strength, 0 }
{
    m_probalityOfCloning = probabilityOfCloning;
    m_nutritionValue = nutritionValue;
}

void Plant::action()
{
    if (double(rand()) / (RAND_MAX + 1) >= m_probalityOfCloning)
    {
        return;
    }

    breed();
    /*
    std::vector<Cell*> neigbours;
    m_world->getNeighbours(m_position, neigbours);
    int a = rand() % neigbours.size();

    if (neigbours[a]->getOrganism() == nullptr)
    {
        m_world->addOrganism(clone(), neigbours[a]->m_row, neigbours[a]->m_column);
    }*/
}

bool Plant::isPlant() const
{
    return true;
}

bool Plant::isAnimal() const
{
    return false;
}

bool Plant::isPoisonous() const
{
    return false;
}

void Plant::breed()
{
    std::vector<Cell*> neigbours;
    m_world->getNeighbours(m_position, neigbours);
    int a = rand() % neigbours.size();

    if (neigbours[a]->getOrganism() == nullptr)
    {
        m_world->addOrganism(clone(), neigbours[a]->getRow(), neigbours[a]->getColumn());
        //m_world->addOrganism(clone(), neigbours[a]->m_row, neigbours[a]->m_column);
    }

}

double Plant::getProbalityOfCloning() const {
    return m_probalityOfCloning;
}

int Plant::getNutritionValue() const {
    return m_nutritionValue;
}

void Plant::setProbalityOfCloning(double probalityOfCloning) {
    m_probalityOfCloning = probalityOfCloning;
}

void Plant::setNutritionValue(int nutritionValue) {
    m_nutritionValue = nutritionValue;
}