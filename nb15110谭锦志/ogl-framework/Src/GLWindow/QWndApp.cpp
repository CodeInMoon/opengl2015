#include "QWndApp.h"
#include "Global.h"

QWndApp::QWndApp()
{
	m_pMainWnd = NULL;
	g_pWndApp = this;  // ����ȫ��appָ��
}

QWndApp::~QWndApp()
{
	
}

BOOL QWndApp::InitInstance()
{
	return true;
}

BOOL QWndApp::ExitInstance()
{
	return true;
}

// ��Ϣѭ��
void QWndApp::run()
{
	// ��Ϣѭ��
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::DispatchMessage(&msg);  // ����
		::TranslateMessage(&msg); // �ɷ�
	}
}

