#include "engine.h"

Engine *engine;

GLvoid MyKey(GLint key, GLint a, GLint b)
{
	engine->MyKeyboard(key, a, b);
}

GLvoid display(GLvoid)
{
	
	engine->Draw();

	glutSwapBuffers();
}

GLvoid reshape(GLsizei width, GLsizei height)
{
	engine->Resize(width, height);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);///������� ����� � ���
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("������ ����, ������");
	engine = new Engine();
	engine->Init();
	///�����������
	glutSpecialFunc(MyKey);///������
	glutDisplayFunc(display);///����������� ����
	glutReshapeFunc(reshape);///��������� �������� ����
	glutIdleFunc(display);///��� ��������
	glutMainLoop();///��������� ������� ��� �������
	return 0;
}
