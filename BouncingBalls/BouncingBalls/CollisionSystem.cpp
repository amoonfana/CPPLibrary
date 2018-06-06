#include <glut.h>
#include "CollisionSystem.h"

CollisionSystem::CollisionSystem() {
	t = 0;
}

CollisionSystem::CollisionSystem(vector<Ball> bs1) {
	t = 0;
	bs = bs1;
	pq = priority_queue<Event>();

	int n = bs.size();
	for (int i = 0; i < n; ++i) { predict(&bs[i]); }
	pq.push(Event(0.0, NULL, NULL));
}

void CollisionSystem::draw() {
	int n = bs.size();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < n; ++i) {
		glBegin(GL_POLYGON);
		for (int j = 0; j < 10; j++){
			glVertex2f(bs[i].rx + bs[i].r*cos(2 * PI*j / 10), bs[i].ry + bs[i].r*sin(2 * PI*j / 10));
		}
		glEnd();
	}
	//glBegin(GL_POINTS);
	//for (int i = 0; i < n; ++i) {
	//	glVertex2f(bs[i].rx, bs[i].ry);
	//}
	//glEnd();

	glutSwapBuffers();

	if (t < LIMIT) { pq.push(Event(t + TimeTick, NULL, NULL)); }
}

void CollisionSystem::predict(Ball* a) {
	if (!a) { return; }

	int n = bs.size();
	double nt, ntX, ntY;

	for (int i = 0; i < n; ++i) {
		nt = t + a->time2Hit(&bs[i]);
		if (nt < LIMIT) { pq.push(Event(nt, a, &bs[i])); }
	}

	ntX = t + a->time2HitVWall();
	if (ntX < LIMIT) { pq.push(Event(ntX, a, NULL)); }

	ntY = t + a->time2HitHWall();
	if (ntY < LIMIT) { pq.push(Event(ntY, NULL, a)); }

}

void CollisionSystem::simulate() {
	if (pq.empty()) { return; }

	int n = bs.size();
	Event e = pq.top();
	pq.pop();
	if (!e.isValid()) { return; }
	Ball *a = e.a, *b = e.b;

	for (int i = 0; i < n; ++i) {
		bs[i].move(e.t - t);
	}
	t = e.t;

	if (a&&b) { a->bounceOff(b); }
	else if (a && !b) { a->bounceOffVWall(); }
	else if (!a&&b) { b->bounceOffHWall(); }
	else if (!a && !b) { draw(); }

	predict(a);
	predict(b);

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(10.0f);

	//glBegin(GL_POINTS);
	//glColor3f(1.0f, 1.0f, 1.0f);
	//for (int i = 0; i < 5; ++i) {
	//	glVertex2f(bs[i].rx, bs[i].ry);
	//	bs[i].rx += 0.005;
	//	bs[i].ry += 0.005;
	//}
	//glEnd();

	//glutSwapBuffers();
}