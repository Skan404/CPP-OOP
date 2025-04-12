#pragma once

class Hogweed :
	public Plant
{
public:
	Hogweed();
	//~Grass();

	void print() override;
	void action() override;
	Hogweed* clone() const override;
	bool isPoisonous() const;
	std::string getSpecies() const;
};

