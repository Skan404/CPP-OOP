#pragma once
#include "Animal.h"

class Sheep :
	public Animal
{
public:
	Sheep();
	//~Sheep();
	void action() override;
	void print() override;
	Sheep* clone() const override;
	std::string getSpecies() const;
};

