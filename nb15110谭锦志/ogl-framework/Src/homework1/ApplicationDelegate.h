#pragma once
#include "../GLWindow/QWndApp.h"

class ApplicationDelegate : QWndApp
{
public:
	ApplicationDelegate();
	~ApplicationDelegate();

public:

	// ��ʼ������
	virtual BOOL InitInstance();

	// �˳�����
	virtual BOOL ExitInstance();
};

extern ApplicationDelegate theApp; // ȫ��app