#include "AppDelegate.h"
#include "MainScene.h"

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{

}

BOOL AppDelegate::InitInstance()
{
	MainScene *pMainWnd = new MainScene();
	if (NULL == pMainWnd)
	{
		return 0; // ���ڴ���ʧ��
	}
	m_pMainWnd = (LPVOID)pMainWnd;  // ����ָ�룬�����˳�ʱ����delete

	pMainWnd->CreateGlWnd("ogl-framework", 30, 20, 800, 600);
	pMainWnd->ShowWindow(SW_SHOW);
	pMainWnd->UpdateWindow();

	return TRUE;
}

BOOL AppDelegate::ExitInstance()
{
	if (m_pMainWnd)
	{
		delete m_pMainWnd;
		m_pMainWnd = NULL;
	}
	return true;
}

