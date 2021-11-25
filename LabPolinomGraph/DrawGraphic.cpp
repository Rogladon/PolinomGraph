#include "pch.h"
#include "DrawGraphic.h"

void DrawGraphic::Draw(CDialogEx* dlg, Polinom* polinom)
{
	CRect rect;
	dlg->GetClientRect(rect);
	CDC* dc = dlg->GetDC();
	CBrush brush(RGB(255, 0, 0));
	dc->SelectObject(brush);
	float k = rect.Width() / polinom->GetDiaposonX();
	DrawCoordsSystem(dlg, k);
	float step = polinom->GetDiaposonX() / 100;
	for (float i = polinom->GetXMin(); i < polinom->GetXMax(); i+=step) {
		float y = polinom->GetCoordY(i);
		int coordY = (int)(-y * k)+rect.Height()/2;
		int coordX = (int)(i * k) + rect.Width() / 2;
		if (i == polinom->GetXMin()) dc->MoveTo(coordX, coordY);
		dc->LineTo(coordX, coordY);
	}
	dlg->ReleaseDC(dc);
}

void DrawGraphic::DrawCoordsSystem(CDialogEx* dlg, float stepCoords)
{
	int stepCount = stepCoords < 10?0:1;
	float step = stepCoords;
	while (step < 10) {
		stepCount+=5;
		step += stepCoords*5;
	}
	CRect rect;
	dlg->GetClientRect(rect);
	CDC* dc = dlg->GetDC();
	CBrush brush(RGB(0, 0, 0));
	dc->SelectObject(brush);
	dc->MoveTo(rect.Width() / 2, 0);
	dc->LineTo(rect.Width() / 2, rect.Height());
	dc->MoveTo(0,rect.Height() / 2);
	dc->LineTo(rect.Width(), rect.Height()/2);
	dc->MoveTo(rect.Width() / 2, rect.Height() / 2);
	CString str = L"";
	str.Format(L"step coords: %i", stepCount);
	dc->TextOutW(0, 0, str);
	for (int i = rect.Width()/2; i < rect.Width(); i+=step) {
		dc->Rectangle(i - 1, rect.Height() / 2 + 5, i + 1, rect.Height()/2 - 5);
	}
	for (int i = rect.Width() / 2; i > 0; i -= step) {
		dc->Rectangle(i - 1, rect.Height() / 2 + 5, i + 1, rect.Height() / 2 - 5);
	}
	for (int i = rect.Height() / 2; i < rect.Height(); i += step) {
		dc->Rectangle(rect.Width() / 2 + 5, i - 1, rect.Width() / 2 - 5, i + 1);
	}
	for (int i = rect.Height() / 2; i > 0; i -= step) {
		dc->Rectangle(rect.Width() / 2 + 5, i - 1, rect.Width() / 2 - 5, i + 1);
	}
	dlg->ReleaseDC(dc);
}
