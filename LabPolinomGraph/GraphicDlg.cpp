#include "pch.h"
#include "LabPolinomGraph.h"
#include "GraphicDlg.h"
#include "afxdialogex.h"
#include "DrawGraphic.h"



IMPLEMENT_DYNAMIC(GraphicDlg, CDialogEx)

GraphicDlg::GraphicDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

GraphicDlg::~GraphicDlg()
{
}

void GraphicDlg::Draw(Polinom* polinom)
{
	DrawGraphic::Draw(this, polinom);
}

void GraphicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GraphicDlg, CDialogEx)
END_MESSAGE_MAP()
