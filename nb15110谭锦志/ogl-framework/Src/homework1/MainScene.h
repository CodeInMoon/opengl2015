#pragma once
#include "../GLWindow/GLWindow.h"  // ʹ��GLWindow �� ����win32��װ�Ĵ���Ӧ�����

class MainScene : public GLWindow
{
public:
	MainScene();
	~MainScene();

	// ��ʼ��
	BOOL initGL(GLvoid);

	// ���Ƴ���
	BOOL DrawGL(GLvoid);

	// ���´�����Ϣ
	BOOL UpdateGL(GLvoid);

	// opengl��������ǰ�Ĵ���
	GLvoid DestroyGL(GLvoid);

private:
	float m_posx;
};