#pragma once

class Milt :
	public Plant
{
public:
	Milt();
	//~Grass();
	void print() override;
	void breed() override;
	Milt* clone() const override;
	std::string getSpecies() const;
};

