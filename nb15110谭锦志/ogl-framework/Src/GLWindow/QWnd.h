#pragma once
#include "stdafx.h"

class QWnd
{
public:
	QWnd();

	// ������
	virtual ~QWnd();

	// ��������
	BOOL CreateEx(DWORD dwExStyle,
		LPCTSTR lpClassName,
		LPCTSTR lpWindowName,
		DWORD dwStyle,
		int x,
		int y,
		int nWidth,
		int nHeight,
		QWnd* pWndParent,
		HMENU hMenu);
private:
	HWND m_hWnd;
};

