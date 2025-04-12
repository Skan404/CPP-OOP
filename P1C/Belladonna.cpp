#include "Headers.h"

Belladonna::Belladonna()
    : Plant{ 0, 0.1, 0 }
{


}

void Belladonna::print()
{
    std::cout << "b";
}

Belladonna* Belladonna::clone() const
{
    return new Belladonna;
}

bool Belladonna::isPoisonous() const
{
    return true;
}

std::string Belladonna::getSpecies() const
{
    return "Belladonna";
}