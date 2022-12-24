#pragma once
#include<vector>

using namespace std;
class Point
{
private:
	vector<double> coordinates;

public:
	Point(int size);
	Point(vector<double> p);
	Point();
	
	double& operator[](int index);

	Point operator+(const Point& point2);
	Point operator-(const Point& point2);
	Point operator*(const double number);
	Point operator/(const double number);

	int size();
};