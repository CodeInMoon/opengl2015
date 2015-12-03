#include "MainScene.h"
#include "../ShaderLoader/LoadShaders.h"
#include <math.h>

MainScene::MainScene()
{
	m_posx = -1.5f;
}

MainScene::~MainScene()
{

}

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs{ArrayBuffer, NumBuffers};
enum Attrib_IDs
{
	vPosition = 0
};


// ��ʾģʽ
void MainScene::ViewMode()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ͸��ģʽ
	gluPerspective(45.0f, this->GetWidth() / this->GetHeight(), 0.01f, 100.0f);

	// �����λ��
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); 

	// ѡ��ģʽ�۲����
	glMatrixMode(GL_MODELVIEW); 

	glLoadIdentity();
}


GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertcies = 6;


BOOL MainScene::initGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);

	// ѡ����Ȳ��Է�
	glDepthFunc(GL_LEQUAL);
	
	glShadeModel(GL_SMOOTH);

	// �ϸ��͸�Ӽ���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

	////////
	
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);
	GLfloat vertices[NumVertcies][2] = {
		{-0.90, -0.90},
		{ 0.85, -0.90},
		{-0.90,  0.85},
		{ 0.90, -0.85},
		{ 0.90,  0.90},
		{-0.85,  0.90}
	};
	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "shader/triangles.vert"},
		{GL_FRAGMENT_SHADER, "shader/triangles.frag"},
		{GL_NONE, NULL}
	};
	GLuint program = LoadShaders(shaders);
	glUseProgram(program); 
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
	
	/////////
	return TRUE;
}

BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// �����ɫ����Ȼ���

	//////////////////////////////////////////////////////////////////////////
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertcies);
	//////////////////////////////////////////////////////////////////////////

	glFlush(); // ˢ��GL�������
	return TRUE;
}

BOOL MainScene::UpdateGL(GLvoid)
{
	/* 
	* ϵͳ����ӳ��˵��
	* F1->F12     : VK_F1 -> VK_F12
	* num 0 -> 9  : VK_NUMPAD0 -> VK_NUMPAD9
	* char A -> Z : 0x41 -> ... ���� 
	*/

	if (keyDown(VK_F1))
	{
		m_posx += 0.01f;
	}

	return TRUE;
}

GLvoid MainScene::DestroyGL(GLvoid)
{

}

