#pragma once
#include "Animal.h"

class Wolf :
	public Animal
{
public:
	Wolf();
	//~Wolf();
	void action() override;
	void print() override;
	Wolf* clone() const override;
	std::string getSpecies() const;
};

