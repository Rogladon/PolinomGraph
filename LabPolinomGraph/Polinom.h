#include <vector>

#pragma once
class Polinom
{
public:
	Polinom(std::vector<float> k);
	Polinom(std::vector<float> k, float xMin, float xMax);
	
	float GetCoordY(float x);
	float GetXMin();
	float GetXMax();
	float GetDiaposonX();
	float GetDiaposonY();
private:
	std::vector<float> k;
	float xMin = -10;
	float xMax = 10;
};

