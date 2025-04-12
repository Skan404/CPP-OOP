#include "Headers.h"

Sheep::Sheep()
    : Animal{ 4 , 4 }
{


}

void Sheep::action()
{
    Animal::action();
}

void Sheep::print()
{
    std::cout << "S";
}

std::string Sheep::getSpecies() const
{
    return "Sheep";
}

Sheep* Sheep::clone() const
{
    return new Sheep;
}