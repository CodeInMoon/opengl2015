/************************************************************************/
/* Ӧ�ó������                                                           */
/************************************************************************/
#pragma once
#include "stdafx.h"

class QWndApp
{
public:
	QWndApp();
	~QWndApp();

public:
	virtual BOOL InitInstance();   // ��ʼ�� app
	virtual BOOL ExitInstance();   // �˳� app
	virtual void run();			   // ����

protected:
	LPVOID m_pMainWnd;
};
