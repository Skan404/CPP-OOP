#include "Headers.h"

Turtle::Turtle()
    : Animal{ 2 , 1 }
{


}

void Turtle::action()
{
    int a = rand() % 4;
    if (a == 0)
    {
        Animal::action();
    }
    else
    {
        return;
    }
}

void Turtle::print()
{
    std::cout << "T";
}

bool Turtle::isAttackCountered(Animal* a) const
{
    return a->getStrength() < 5;
}

std::string Turtle::getSpecies() const
{
    return "Turtle";
}

Turtle* Turtle::clone() const
{
    return new Turtle;
}