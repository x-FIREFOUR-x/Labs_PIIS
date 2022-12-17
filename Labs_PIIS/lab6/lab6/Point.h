#pragma once
#include<vector>

using namespace std;
class Point
{
private:
	vector<float> coordinates;

public:
	Point(int size);
	Point(vector<float> p);
	Point();
	
	float& operator[](int index);

	Point operator+(const Point& point2);
	Point operator-(const Point& point2);
	Point operator*(const float number);
	Point operator/(const float number);

	int size();
};

