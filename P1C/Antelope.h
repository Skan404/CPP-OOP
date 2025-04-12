#pragma once
#include "Animal.h"

class Antelope :
	public Animal
{
public:
	Antelope();
	//~Antelope();
	void action() override;
	void print() override;
	
	bool escapeAttack() override;
	Antelope* clone() const override;
	std::string getSpecies() const;
};

