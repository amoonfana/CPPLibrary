#include <glut.h>
#include "CollisionSystem.h"

CollisionSystem cs;

void myInit(int n) {
	vector<Ball> bs(n);
	for (int i = 0; i < n; ++i) {
		bs[i] = Ball();
	}
	//bs[0] = Ball(0.042672784317306416, 0.7654178552702625, -0.00860332478391284, 0.005097332896967893, 0.02, 10);
	//bs[1] = Ball(0.7539700753880386, 0.3309580819794568, 0.0010676106672899632, -0.009942847050170725, 0.02, 10);
	//bs[2] = Ball(0.5693743292600613, 0.8582692954326814, -0.0023618764330909014, 0.009717074648000281, 0.02, 10);
	//bs[3] = Ball(0.7564833551290755, 0.3725526271686985, 0.00924973226974307, -0.0038003227413041804, 0.02, 10);
	//bs[4] = Ball(0.6658559627340392, 0.20007792878420952, 0.00722542357320046, 0.006913266535281212, 0.02, 10);

	cs = CollisionSystem(bs);
}

void myReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay() {
	cs.simulate();
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowSize(800, 800);
	glutCreateWindow("Bouncing Balls");

	myInit(100);
	glutReshapeFunc(&myReshape);
	glutDisplayFunc(&myDisplay);

	glutMainLoop();

	return 0;
}
