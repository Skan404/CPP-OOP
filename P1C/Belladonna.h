#pragma once

class Belladonna :
	public Plant
{
public:
	Belladonna();
	//~Belladonna();

	void print() override;
	Belladonna* clone() const override;
	bool isPoisonous() const;
	std::string getSpecies() const;
};

