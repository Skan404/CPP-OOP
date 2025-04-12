#pragma once
#include "Animal.h"

class Fox :
	public Animal
{
public:
	Fox();
	//~Fox();
	void action() override;
	void print() override;
	Fox* clone() const override;
	std::string getSpecies() const;
};

