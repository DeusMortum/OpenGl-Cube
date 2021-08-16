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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);///Двойной буфер и РГБ
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Приедь проц, приедь");
	engine = new Engine();
	engine->Init();
	///Регистрация
	glutSpecialFunc(MyKey);///кнопок
	glutDisplayFunc(display);///перерисовка окна
	glutReshapeFunc(reshape);///изменение размеров окна
	glutIdleFunc(display);///для анимации
	glutMainLoop();///обработка событий при простое
	return 0;
}
