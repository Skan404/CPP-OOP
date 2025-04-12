#pragma once

class Plant
	: public Organism
{
private:
	double m_probalityOfCloning;
	int	m_nutritionValue;
public:
	Plant(int strength, double probalityOfCloning, int m_nutritionValue);
	void action() override;
	bool isAnimal() const override;
	void setProbalityOfCloning(double probalityOfCloning);
	void setNutritionValue(int nutritionValue);
	double getProbalityOfCloning() const;
	int getNutritionValue() const;
	bool isPlant() const override;
	virtual bool isPoisonous() const;
	virtual void breed();
};
