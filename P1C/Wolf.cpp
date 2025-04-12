#include "Headers.h"

Wolf::Wolf()
    : Animal{ 9 , 5 }
{


}

void Wolf::action()
{
    Animal::action();
}

void Wolf::print()
{
    std::cout << "W";
}

std::string Wolf::getSpecies() const
{
    return "Wolf";
}

Wolf* Wolf::clone() const
{
    return new Wolf;
}