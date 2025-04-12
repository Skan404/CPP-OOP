#pragma once

class Grass :
	public Plant
{
public:
	Grass();
	//~Grass();

	void print() override;
	Grass* clone() const override;
	std::string getSpecies() const;
};

