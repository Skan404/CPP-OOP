#pragma once


class Cell

{
private:
	int m_row;
	int m_column;
public: 
	std::vector<Organism*> m_organisms;


	Organism* getOrganism() const;
	void setRow(int row);
	void setColumn(int column);
	int getRow() const;
	int getColumn() const;

};