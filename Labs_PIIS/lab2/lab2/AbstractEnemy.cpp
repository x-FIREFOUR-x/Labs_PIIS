#include "AbstractEnemy.h"

AbstractEnemy::AbstractEnemy(pair<int, int> coordinates)
{
	this->line = coordinates.first;
	this->column = coordinates.second;
}

AbstractEnemy::AbstractEnemy(int line, int column)
{
	this->line = line;
	this->column = column;
}

int AbstractEnemy::get_line() const
{
	return this->line;
}

int AbstractEnemy::get_column() const
{
	return this->column;
}

pair<int, int> AbstractEnemy::get_coordinates() const
{
	return make_pair(this->line, this->column);
}