#pragma once

class Human
	: public Animal
{

private:
	int m_specialAbilityRemaining = 0;
	int m_specialAbilityPauseRemaining = 0;
public: 
	
	Human(int strength, int specialAbilityRemaning, int specialAbilityPauseRemaning);
	void action() override;
	CollisionResult collision(Organism* o) override;
	void print() override;
	std::string getSpecies() const;
	int getspecialAbilityRemaining();
	int getspecialAbilityPauseRemaining();
	bool isAttackRepelled() const;
	bool canActivateSpecialAbility() const;
	void activateSpecialAbility();

};