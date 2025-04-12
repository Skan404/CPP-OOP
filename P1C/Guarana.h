#pragma once

class Guarana :
	public Plant
{
public:
	Guarana();
	//~Guarana();

	void print() override;
	Guarana* clone() const override;
	std::string getSpecies() const;
};

