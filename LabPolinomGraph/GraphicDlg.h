#include "Polinom.h"

#pragma once


class GraphicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GraphicDlg)

public:
	GraphicDlg(CWnd* pParent = nullptr);
	virtual ~GraphicDlg();
	void Draw(Polinom* polinom);


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); 

	DECLARE_MESSAGE_MAP()
};
