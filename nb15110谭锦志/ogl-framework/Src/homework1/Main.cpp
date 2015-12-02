/************************************************************************/
/* time   : 2015-12-02                                                  */
/* author : ̷��־                                                       */
/* email  : apanoo@126.com                                              */
/************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include "Main.h"

//link to libraries
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "winmm.lib")

// ��������Ϣ
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		::DestroyWindow(hWnd); // ���ٴ���
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);  // �Ƴ�����
		break;
	default:
		break;
	}
	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// WinMain ��ں���
int WINAPI _tWinMain(	HINSTANCE	hInstance,			//Instance
						HINSTANCE	hPrevInstance,		//Previous Instance
						LPSTR		lpCmdLine,			//Command line params
						int			nShowCmd)			//Window show state
{
	WNDCLASSEX wcex;
	wcex.cbClsExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)::GetStockObject(GRAY_BRUSH);
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW); 
	wcex.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wcex.hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = "OpenGL";
	wcex.lpszMenuName = NULL;
	wcex.style = CS_VREDRAW | CS_HREDRAW;

	BOOL bRet = ::RegisterClassEx(&wcex); // ע�ᴰ��
	if (!bRet)
	{
		return 0; // ע�ᴰ����ʧ��
	}

	// ��������
	HWND hWnd = ::CreateWindowEx(0, wcex.lpszClassName, "ogl-framework", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (NULL == hWnd)
	{
		return 0; // ��������ʧ��
	}

	::ShowWindow(hWnd, SW_SHOW);
	::UpdateWindow(hWnd);

	// ��Ϣѭ��
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::DispatchMessage(&msg);  // ����
		::TranslateMessage(&msg); // �ɷ�
	}

	return 0;
}
