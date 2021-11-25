#include "pch.h"
#include "framework.h"
#include "LabPolinomGraph.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "Polinom.h"
#include "GraphicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LABPOLINOMGRAPH_DIALOG, pParent)
	, x0(0)
	, x1(0)
	, x2(0)
	, x3(0)
	, x4(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x0);
	DDX_Text(pDX, IDC_EDIT2, x1);
	DDX_Text(pDX, IDC_EDIT3, x2);
	DDX_Text(pDX, IDC_EDIT4, x3);
	DDX_Text(pDX, IDC_EDIT5, x4);
	DDX_Text(pDX, IDC_EDIT6, xMin);
	DDX_Text(pDX, IDC_EDIT7, xMax);
	DDX_Text(pDX, IDC_EDIT8, x5);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
END_MESSAGE_MAP()



BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	xMin = -10;
	xMax = 10;
	UpdateData(FALSE);

	return TRUE;
}

void MainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);


		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;


		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR MainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void MainDlg::OnBnClickedButton1()
{
	if(!UpdateData(TRUE)) return;

	if (xMin >= xMax) {
		CString str;
		str.Format(L"x=[%d,%d] - Нижний диапозон не может \nбыть больше или равен верхнему", xMin, xMax);
		MessageBox(str);
		return;
	}

	std::vector<float> k = std::vector<float>();
	k.push_back(x0);
	k.push_back(x1);
	k.push_back(x2);
	k.push_back(x3);
	k.push_back(x4);
	k.push_back(x5);

	Polinom* polinom = new Polinom(k,xMin,xMax);

	GraphicDlg* dlg = new GraphicDlg(this);

	dlg->Create(IDD_DIALOG1);
	dlg->SetActiveWindow();
	dlg->Draw(polinom);
}
