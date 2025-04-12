#include "Headers.h"

Grass::Grass()
    : Plant{ 0, 0.1, 0 }
{


}

void Grass::print()
{
    std::cout << "g";
}

Grass* Grass::clone() const
{
    return new Grass;
}

std::string Grass::getSpecies() const
{
    return "Grass";
}