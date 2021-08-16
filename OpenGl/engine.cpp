#include "engine.h"
GLuint  texture[6]; ///����� �������
GLfloat xrot;          /// �������� X
GLfloat yrot;          /// Y
bool keys[256];  ///������
int parm = 0;

int LoadGLTextures()                                    
{
	
	texture[0] = SOIL_load_OGL_texture ///�������� �������
	(
		"text1.jpg",
		SOIL_LOAD_AUTO,///�����������  �� �����
		SOIL_CREATE_NEW_ID,///����� �������������
		SOIL_FLAG_INVERT_Y/// ����������� ��� y �����������
		///����� ��� ������� ����������� ��������, ������� � ������ �������� ����,
		///� OpenGL ���������� ������ ����������� � ����� ������ ����
	);
	texture[1] = SOIL_load_OGL_texture
	(
		"text2.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[2] = SOIL_load_OGL_texture
	(
		"text3.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[3] = SOIL_load_OGL_texture
	(
		"text4.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[4] = SOIL_load_OGL_texture
	(
		"text5.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[5] = SOIL_load_OGL_texture
	(
		"text6.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	if (texture[0] == 0 && texture[1] == 1 && texture[2] == 2 && texture[3] == 3 && texture[4] == 4 && texture[5] == 5)
		return false;



		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	///���������� ��������
	///������� ������� ��������� � ���������� ����������� ��������

	return true;                                        
}

GLvoid Engine::SetProjectionMatrix(GLvoid){

	glMatrixMode(GL_PROJECTION);						
	glLoadIdentity();									/// ������� ������� ������������ �� ���������
	gluPerspective(45.0f, 1.5f, 0.1f, 100.0f);
	// ��������� � ������� ��������
	glMatrixMode(GL_MODELVIEW);					
}

GLvoid Engine::SetModelviewMatrix(GLvoid){
	glMatrixMode(GL_MODELVIEW);							/// ������� ������
	glLoadIdentity();									/// ������� ������� ������������ �� ���������
	glTranslatef(0.0, 0.0, -8.0);																	
	glRotatef(30.0, 1.0, 0.0, 0.0);
}

GLvoid Engine::Resize(GLsizei width, GLsizei height){
	if (height == 0)									
	{
		height = 1;										
	}

	glViewport(0, 0, width, height);					///  ������� ���������

	Height = height;
	Width = width;

	SetProjectionMatrix();
	SetModelviewMatrix();
}

GLvoid Engine::Init(GLvoid){
	LoadGLTextures();           // �������� �������
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.2f, 0.5f, 0.75f, 1.0f);				///  ����� ���
	glClearDepth(1.0f);									/// �������� ��� ���������� ������ ������� �� ���������
														
	glEnable(GL_DEPTH_TEST);							/// ���������� ���� �������
	glDepthFunc(GL_LEQUAL);								/// ��������, ������������  � ���������� ��� ������������� ������ �������
														


	glShadeModel(GL_SMOOTH);							///  ������� ���������
	glEnable(GL_LINE_SMOOTH);							///  ����������� �����
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);				///  ������������ ����� ����������� ��� �����
													
	glEnable(GL_BLEND);									/// ���������� �������� ������, �����������
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	/// ��� ������ ����������� � �������� ������ ��������
														
}

GLvoid Engine::MyKeyboard(GLint key, GLint a, GLint b)
{

	switch (key)
	{


	case 100: yrot += 0.7; break;
	case 102: yrot -= 0.7; break;
	case 103: xrot += 0.7; break;
	case 101: xrot -= 0.7; break;



	}

	/*101= �����
		102 = ����
		100 �����
		103 ������*/
}

GLvoid Engine::Draw(GLvoid)									
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);     /// �������� �� ��� X
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);     /// �������� �� ��� Y

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);/// �������� �����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// ��� ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// ��� �����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// ���� �����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// ���� ����
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[1]);		
	glBegin(GL_QUADS);/// ������ �����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); /// ��� �����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// ���� �����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// ���� ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// ��� ����
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);/// ������� �����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// ���� ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// ��� ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// ��� �����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// ���� �����
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[3]);		
	glBegin(GL_QUADS);/// ������ �����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  /// ���� �����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// ���� ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// ��� ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// ��� �����
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[4]);	
	glBegin(GL_QUADS);/// ������ �����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// ��� �����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// ���� �����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// ���� ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// ��� ����
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);////// ����� �����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  /// ��� ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// ��� �����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// ���� �����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// ���� ����
	glEnd();


						
}


