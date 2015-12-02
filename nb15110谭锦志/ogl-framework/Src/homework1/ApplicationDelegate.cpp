#include "ApplicationDelegate.h"

ApplicationDelegate::ApplicationDelegate()
{

}

ApplicationDelegate::~ApplicationDelegate()
{

}

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


ApplicationDelegate theApp;
BOOL ApplicationDelegate::InitInstance()
{
	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(NULL);
	assert(hInstance);

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
}

BOOL ApplicationDelegate::ExitInstance()
{
	return true;
}

