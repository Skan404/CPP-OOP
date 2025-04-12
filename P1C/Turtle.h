#pragma once
#include "Animal.h"

class Turtle :
	public Animal
{
public:
	Turtle();
	//~Turtle();
	void action() override;
	void print() override;
	Turtle* clone() const override;
	bool isAttackCountered(Animal* a) const override;
	std::string getSpecies() const;
};

