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

	glutSwapBuffers(); // îòðèñîâêà
}

static void InitializeGlutCallbacks() {
	glutDisplayFunc(RenderSceneCB); // Ýòà ôóíêöèÿ ðåãóëÿðíî âûçûâàåòñÿ GLUT'îì.
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
	glutInit(&argc, argv); // Èíèöèàëèçàöèÿ OpenGL utility library ñ ïàðàìåòðàìè èç êîìàíäíîé ñòðîêè
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // GLUT_DOUBLE âêëþ÷àåò äâîéíóþ áóôåðèçàöèþ, GLUT_RGBA - áóôåð öâåòà, íåïðåðûâíî èñïîëüçóåìîãî äëÿ êîíå÷íîé öåëè ðåíäåðèíãà (ò.å. íà ýêðàíå).
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Task 3"); // Ýòè ôóíêöèè çàäàþò ïàðàìåòðû îêíà è ñîçäàþò åãî. Òàê æå ìû äàåì åìó çàãîëîâîê.

	InitializeGlutCallbacks(); // ôóíêöèÿ îáðàòíîãî âûçîâà.

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return;
	} // Òåïåðü ìû èíèöèàëèçèðóåì GLEW è ïðîâåðÿåì íà îøèáêè. GLUT íåîáõîäèìî èíèöèàëèçèðîâàòü ïåðåä ýòèì.

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // óñòàíàâëèâàåò öâåò, êîòîðûé áóäåò èñïîëüçîâàí âî âðåìÿ î÷èñòêè áóôåðà êàäðà.

	CreateVertexBuffer(); // ñîçäàíèå òðåóãîëüíèêà.

	glutMainLoop(); // ïåðåäà÷à óïðàâëåíèÿ GLUT.
}
