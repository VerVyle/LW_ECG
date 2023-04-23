#include "tasks.h"
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO1;

static void RenderSceneCB() {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	glutSwapBuffers(); // ���������
}

static void InitializeGlutCallbacks() {
	glutDisplayFunc(RenderSceneCB); // ��� ������� ��������� ���������� GLUT'��.
}

static void CreateVertexBuffer() {
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

void invoke3(int argc, char** argv) {
	glutInit(&argc, argv); // ������������� OpenGL utility library � ����������� �� ��������� ������
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // GLUT_DOUBLE �������� ������� �����������, GLUT_RGBA - ����� �����, ���������� ������������� ��� �������� ���� ���������� (�.�. �� ������).
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Task 3"); // ��� ������� ������ ��������� ���� � ������� ���. ��� �� �� ���� ��� ���������.

	InitializeGlutCallbacks(); // ������� ��������� ������.

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return;
	} // ������ �� �������������� GLEW � ��������� �� ������. GLUT ���������� ���������������� ����� ����.

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ������������� ����, ������� ����� ����������� �� ����� ������� ������ �����.

	CreateVertexBuffer(); // �������� ������������.

	glutMainLoop(); // �������� ���������� GLUT.
}