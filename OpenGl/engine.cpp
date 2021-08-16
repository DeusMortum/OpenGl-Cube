#include "engine.h"
GLuint  texture[6]; ///Масив текстур
GLfloat xrot;          /// Вращение X
GLfloat yrot;          /// Y
bool keys[256];  ///Кнопки
int parm = 0;

int LoadGLTextures()                                    
{
	
	texture[0] = SOIL_load_OGL_texture ///Загрузка текстур
	(
		"text1.jpg",
		SOIL_LOAD_AUTO,///изображение  на диске
		SOIL_CREATE_NEW_ID,///новый идентификатор
		SOIL_FLAG_INVERT_Y/// перевернуть ось y изображения
		///Почти все форматы изображений хранятся, начиная с левого верхнего угла,
		///а OpenGL определяет начало изображения в левом нижнем углу
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
	///Фильтрация линейная
	///Среднее четырех ближайших к полученным координатам текселей

	return true;                                        
}

GLvoid Engine::SetProjectionMatrix(GLvoid){

	glMatrixMode(GL_PROJECTION);						
	glLoadIdentity();									/// Текущая матрица сбрасывается на единичную
	gluPerspective(45.0f, 1.5f, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);					
}

GLvoid Engine::SetModelviewMatrix(GLvoid){
	glMatrixMode(GL_MODELVIEW);							/// матрица модели
	glLoadIdentity();									/// Текущая матрица сбрасывается на единичную
	glTranslatef(0.0, 0.0, -8.0);																	
	glRotatef(30.0, 1.0, 0.0, 0.0);
}

GLvoid Engine::Resize(GLsizei width, GLsizei height){
	if (height == 0)									
	{
		height = 1;										
	}

	glViewport(0, 0, width, height);					///  область просмотра

	Height = height;
	Width = width;

	SetProjectionMatrix();
	SetModelviewMatrix();
}

GLvoid Engine::Init(GLvoid){
	LoadGLTextures();           // Загрузка текстур
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.2f, 0.5f, 0.75f, 1.0f);				///  синий фон
	glClearDepth(1.0f);									/// значение для заполнения буфера глубины по умолчанию
														
	glEnable(GL_DEPTH_TEST);							/// Включается тест глубины
	glDepthFunc(GL_LEQUAL);								/// значение, используемое  в сравнениях при использовании буфера глубины
														


	glShadeModel(GL_SMOOTH);							///  плавное затенение
	glEnable(GL_LINE_SMOOTH);							///  сглаживание линий
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);				///  качественный режим сглаживания для линий
													
	glEnable(GL_BLEND);									/// Включается смешение цветов, необходимое
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	/// для работы сглаживания и задается способ смешения
														
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

	/*101= влево
		102 = вниз
		100 вверх
		103 вправо*/
}

GLvoid Engine::Draw(GLvoid)									
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);     /// Вращение по оси X
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);     /// Вращение по оси Y

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);/// Передняя грань
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// Верх лево
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[1]);		
	glBegin(GL_QUADS);/// Задняя грань
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); /// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// Низ лево
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);/// Верхняя грань
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// Верх право
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[3]);		
	glBegin(GL_QUADS);/// Нижняя грань
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  /// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// Низ право
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[4]);	
	glBegin(GL_QUADS);/// Правая грань
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// Низ лево
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);////// Левая грань
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  /// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// Верх лево
	glEnd();


						
}


