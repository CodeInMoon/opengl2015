#include "MainScene.h"

MainScene::MainScene()
{
	m_posx = -1.5f;
}

MainScene::~MainScene()
{

}

BOOL MainScene::initGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	// ѡ����Ȳ��Է�
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // �ϸ��͸�Ӽ���

	return TRUE;
}

BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// �����ɫ����Ȼ���
	glLoadIdentity();
	// ���õ�ǰ����
	glFlush();

	int NUM = 200;
	// �������Բʱ�õĶ�����(�ö�����ɵ��߶αƽ�Բ)(new)
	GLfloat r = 1.0f;
	// ����Բ�뾶(new)
	glTranslatef(m_posx, 1.0f, -7.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	// ����������
	glVertex3f(0.0f, 1.0f, 0.0f);
	// �϶���
	glVertex3f(-1.0f, -1.0f, 0.0f);
	// ���¶���
	glVertex3f(1.0f, -1.0f, 0.0f);
	// ���¶���
	glEnd();

	// ˢ��GL�������
	return TRUE;
}

BOOL MainScene::UpdateGL(GLvoid)
{
	/* 
	* ϵͳ����ӳ��˵��
	* F1->F12     : VK_F1 -> VK_F12
	* num 0 -> 9  : VK_NUMPAD0 -> VK_NUMPAD9
	* char A -> Z : 0x41 -> ... ���� ��
	*/

	if (keyUp(0x41))
	{
		m_posx += 0.01f;
	}

	return TRUE;
}

GLvoid MainScene::DestroyGL(GLvoid)
{

}

