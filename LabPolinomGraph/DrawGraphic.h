#include "Polinom.h"

#pragma once
class DrawGraphic
{
public: 
	static void Draw(CDialogEx* dc, Polinom* polinom);
	static void DrawCoordsSystem(CDialogEx* dc, float step);
};

