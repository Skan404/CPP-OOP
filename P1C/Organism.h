#pragma once

class World;
class Cell;

class Organism
{
	friend class World;
protected:
	World* m_world;
	Cell* m_position;
	int m_strength;
	int m_initiative;
	int m_birthday;
	bool m_destroyed;

public:
	Organism(int strength, int initiative);
	virtual ~Organism() = default;

	int getStrength() const;

	int getInitiative() const;

	int getAge() const;

	World* getWorld() const;
	void setWorld(World* world);

	Cell* getPosition() const;
	void setPosition(Cell* position);

	virtual void action();

	virtual CollisionResult collision(Organism* o);
	
	virtual void print();

	virtual Organism* clone() const;
	
	virtual bool isAttackCountered(Organism* o) const;

	virtual bool isPlant() const = 0;

	virtual bool isAnimal() const = 0;

	virtual std::string getSpecies() const = 0;


};
