#include "pch.h"
#include "Polinom.h"

Polinom::Polinom(std::vector<float> k)
{
	this->k = k;
}

Polinom::Polinom(std::vector<float> k, float xMin, float xMax)
{
	this->k = k;
	this->xMin = xMin;
	this->xMax = xMax;
}

float Polinom::GetCoordY(float x)
{
	float y = 0;
	for (int i = 0; i < k.size(); i++) {
		y += pow(x,i) * k[i];
	}
	return y;
}

float Polinom::GetXMin()
{
	return xMin;
}

float Polinom::GetXMax()
{
	return xMax;
}

float Polinom::GetDiaposonX()
{
	float diapos = abs(xMax - xMin);
	float dip = max(abs(xMin), abs(xMax));
	float dopalt = max(abs(xMin), abs(xMax)) * 2;
	return diapos>max(abs(xMin),abs(xMax))?diapos: max(abs(xMin), abs(xMax)) *2;
}
float Polinom::GetDiaposonY()
{
	float diapos = abs(GetCoordY(xMax) - GetCoordY(xMin));
	return diapos > max(GetCoordY(xMin), GetCoordY(xMax)) ? diapos : abs(max(GetCoordY(xMin), GetCoordY(xMax))) * 2;
}
