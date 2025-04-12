#pragma once
#include <fstream>
#include <vector>

class Human;

class World
{
private:
	void moveToEmptyCell(Organism* o, Cell* position);
	void clear();
	void start(int row, int column, int rowPosition, int columnPosition, int strength, int specialAbilityRemaning, int specialAbilityCooldown);

protected:
	int m_width, m_height;
	int m_turn = 0;
	Human* m_human;
	int m_humanDirectionC = 0;
	int m_humanDirectionR = 0;
	std::vector<Organism*> m_organisms;
	std::vector<std::vector<Cell>> m_cells;

public:
	World(int width, int height, int humanR, int humanC);

	void addOrganism(Organism* o, int row, int column);

	World(int N, int M, std::ifstream& loadFile);
	
	int getN();
	int getM();
	int getTurn() const;
	void makeTurn();

	void printWorld();

	void getNeighbours(Cell* position, std::vector<Cell*>& neighbours);
	
	Cell* getCellOrNull(int row, int column);

	void moveTo(Organism* o, Cell* position);

	void action();

	Human* getHuman();

	int getHumanDirectionC() const;

	int getHumanDirectionR() const;

	void setHumanDirection(int directionR, int directionC);

	void kill(Organism* o);

	void getNeighboursWithoutOrganism(Cell* position, std::vector<Cell*>& neighbours);

	void printInformations();

	bool isGameFinished() const;

	void saveState(const std::string& path);
	void loadState(const std::string& path);
};
