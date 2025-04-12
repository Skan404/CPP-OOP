#include "Headers.h"

Guarana::Guarana()
    : Plant{ 0, 0.1, 3 }
{


}

void Guarana::print()
{
    std::cout << "g";
}

Guarana* Guarana::clone() const
{
    return new Guarana;
}

std::string Guarana::getSpecies() const
{
    return "Guarana";
}