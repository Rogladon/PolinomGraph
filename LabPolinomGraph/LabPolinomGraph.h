
// LabPolinomGraph.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// App:
// Сведения о реализации этого класса: LabPolinomGraph.cpp
//

class App : public CWinApp
{
public:
	App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern App theApp;
