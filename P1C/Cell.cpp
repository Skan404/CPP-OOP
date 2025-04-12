#include "Headers.h"

Organism* Cell::getOrganism() const
{
	if (m_organisms.size() != 0)
	{
		return m_organisms[0];
	}

	return nullptr;
}

int Cell::getColumn() const
{
	return m_column;
}

int Cell::getRow() const
{
	return m_row;
}

void Cell::setRow(int row)
{
	m_row = row;
}

void Cell::setColumn(int column)
{
	m_column = column;
}