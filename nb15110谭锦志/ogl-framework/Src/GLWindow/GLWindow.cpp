/*
*  author : ̷��־
*  email  : apanoo@126.com
*  time   : 2014 07 20
*  ps     : ����win32 API��װ
*			֧��win32��׼�ؼ���ȫ�Ի�
*			֧��opengl
*  �ο�    : MFCʵ�ֻ���
*  use     : �����дwindows��ͼ��Ӧ�ü����
*/

#include "GLWindow.h"
// #include <stdio.h>

GLWindow::GLWindow()
{

}

GLWindow::~GLWindow()
{

}

// ����opengl����
BOOL GLWindow::CreateGlWnd(const char* title, int x, int y, int width, int height)
{
	CreateEx(0, "OpenGL", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		x, y, width, height, NULL, NULL);

	if (!(m_hDc = GetDC(m_hWnd)))  // ��ȡDC
	{
		DestroyGL();  // ����
		return FALSE;		  // ���ܻ�ȡDC
	}

	m_timerFrame = 1000;   // ��ʼ��

	GLuint PixelFormat;
	static PIXELFORMATDESCRIPTOR pdf = {
		sizeof(PIXELFORMATDESCRIPTOR),  // �ṹ���С
		1,					  // �汾��
		PFD_DRAW_TO_WINDOW |  // ֧�ִ���
		PFD_SUPPORT_OPENGL |  // ֧��opengl
		PFD_DOUBLEBUFFER,     // ֧��˫����
		PFD_TYPE_RGBA,        // ����RGBA��ʽ
		16,					  // ɫ�����
		0, 0, 0, 0, 0, 0,     // ���Ե�ɫ��λ
		0,					  // ��alpha����
		0,					  // ��shift Bit
		0,					  // ���ۼӻ���
		0, 0, 0, 0,			  // ���Ծۼ�λ
		16,					  // 16λZ-����
		0,					  // ���ɰ滺��
		0,					  // �޸�������
		PFD_MAIN_PLANE,		  // ����ͼ��
		0,					  // Reserved
		0, 0, 0				  // ���Բ�����
	};
	if (!(PixelFormat = ChoosePixelFormat(m_hDc, &pdf)))  // Ѱ����Ӧ���ظ�ʽ
	{
		DestroyGL();  // ����
		// printf("1====error choose====");
		return FALSE;
	}
	if (!SetPixelFormat(m_hDc, PixelFormat, &pdf))
	{
		DestroyGL();
		// printf("1====error choose====");
		return FALSE;
		// �����������ظ�ʽ
	}
	if (!(m_hRc = wglCreateContext(m_hDc)))
	{
		DestroyGL();
		// printf("2====error create context====");
		return FALSE;      // ���ܻ����ɫ������
	}
	if (!wglMakeCurrent(m_hDc, m_hRc))
	{
		DestroyGL();
		// printf("3========");
		return FALSE;      // ���ܼ��ǰopengl��Ⱦ������
	}

	ResizeGLScene(width, height);  // ����GL��Ļ
	if (!initGL())   // ��ʼ��opengl
	{
		DestroyGL();
		return FALSE;
	}

	// �趨��ʱ�� ÿ��ˢ��60��
	SetTimer(m_hWnd, m_timerFrame, 1000 / 60, NULL);

	return TRUE;
}

HRESULT GLWindow::OnClose(WPARAM wParam, LPARAM lParam)
{
	return DestroyWindow();
}

LRESULT GLWindow::OnDestroy(WPARAM wParam, LPARAM lParam)
{
	DestroyGL(); // �˳�����ǰ����opengl
	PostQuitMessage(0);
	return 0;
}

GLvoid GLWindow::ResizeGLScene(GLsizei width, GLsizei height)
{
	if (0 == height)
	{
		height = 1;  // ��ֹ��0��
	}
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ͸��ģʽ
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW); // ѡ��ģʽ�۲����
	glLoadIdentity();
}

BOOL GLWindow::initGL(GLvoid)
{
	return TRUE;
}

BOOL GLWindow::DrawGL(GLvoid)
{
	return TRUE;
}

BOOL GLWindow::UpdateGL(GLvoid)
{
	return TRUE;
}

GLvoid GLWindow::DestroyGL(GLvoid)
{
	if (m_hRc)
	{
		if (!wglMakeCurrent(NULL, NULL))
		{
			// �ͷ�DC��RCʧ��
		}
		if (!wglDeleteContext(m_hRc))
		{
			// �ͷ�RCʧ��
		}
		m_hRc = NULL;
	}
	if (m_hDc && !ReleaseDC(m_hWnd, m_hDc))
	{
		// �ͷ�DCʧ��
		m_hDc = NULL;
	}
	if (m_hWnd && !DestroyWindow())
	{
		// �ͷŴ��ھ��ʧ��
		m_hWnd = NULL;
	}

	// ע����ʱ��
	::KillTimer(m_hWnd, m_timerFrame);
}

BOOL GLWindow::keyUp(int key)
{
	return m_keys[key] == TRUE ? TRUE : FALSE;
}

HRESULT GLWindow::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	if (wParam >= 0 && wParam < 256)
	{
		m_keys[wParam] = TRUE;
	}
	return 0;
}

HRESULT GLWindow::OnKeyUp(WPARAM wParam, LPARAM lParam)
{
	if (wParam >= 0 && wParam < 256)
	{
		m_keys[wParam] = FALSE;
	}
	return 0;
}

HRESULT GLWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	ResizeGLScene(LOWORD(lParam), HIWORD(lParam));
	return 0;
}

HRESULT GLWindow::OnTimer(WPARAM wParam, LPARAM lParam)
{
	UpdateGL();  // ��Ϣ����:���̵�
	return ::InvalidateRect(m_hWnd, NULL, FALSE); // ʹ����ʧЧ
}

HRESULT GLWindow::OnPaint(WPARAM wParam, LPARAM lParam)
{
	DrawGL();						// ����opengl����
	SwapBuffers(m_hDc);				// ��������
	::ValidateRect(m_hWnd, NULL);   // ʹ������Ч
	return TRUE;
}


