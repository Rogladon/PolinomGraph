#pragma once


class MainDlg : public CDialogEx
{
public:
	MainDlg(CWnd* pParent = nullptr);

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABPOLINOMGRAPH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV



protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	FLOAT x0;
	FLOAT x1;
	FLOAT x2;
	FLOAT x3;
	FLOAT x4;
	afx_msg void OnBnClickedButton1();
	FLOAT xMin;
	FLOAT xMax;
	FLOAT x5;
};
