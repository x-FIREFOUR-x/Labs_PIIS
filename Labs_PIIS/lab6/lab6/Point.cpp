#include "Point.h"

Point::Point(int size)
{
	coordinates.resize(size, 0);
}

Point::Point(vector<double> p)
{
	coordinates = p;
}

Point::Point()
{

}

double& Point::operator[](int index)
{
	return coordinates[index];
}

Point Point::operator+(const Point& point2)
{
	Point result(coordinates.size());

	for (int i = 0; i < coordinates.size(); i++)
	{
		result.coordinates[i] = this->coordinates[i] + point2.coordinates[i];
	}

	return result;
}

Point Point::operator-(const Point& point2)
{
	Point result(coordinates.size());

	for (int i = 0; i < coordinates.size(); i++)
	{
		result.coordinates[i] = this->coordinates[i] - point2.coordinates[i];
	}

	return result;
}

Point Point::operator*(const double number)
{
	Point result(coordinates.size());

	for (int i = 0; i < coordinates.size(); i++)
	{
		result.coordinates[i] = this->coordinates[i] * number;
	}

	return result;
}

Point Point::operator/(const double number)
{
	Point result(coordinates.size());

	for (int i = 0; i < coordinates.size(); i++)
	{
		result.coordinates[i] = this->coordinates[i] / number;
	}

	return result;
}

int Point::size()
{
	return coordinates.size();
}
