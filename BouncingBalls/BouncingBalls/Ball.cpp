#include <algorithm>
#include "Ball.h"

using namespace std;

Ball::Ball() {
	rx = ((double)rand()) / RAND_MAX;
	ry = ((double)rand()) / RAND_MAX;
	vx = (((double)rand()) / RAND_MAX - 0.5) / 100;
	vy = (((double)rand()) / RAND_MAX - 0.5) / 100;
	r = 0.01;
	m = 0.5;
	cnt = 0;
}

Ball::Ball(double rx1, double ry1, double vx1, double vy1, double r1, double m1) {
	rx = rx1;
	ry = ry1;
	vx = vx1;
	vy = vy1;
	r = r1;
	m = m1;
	cnt = 0;
}

void Ball::move(double dt) {
	rx += vx*dt;
	ry += vy*dt;
}

double Ball::time2Hit(Ball* b) {
	if (this == b) { return LIMIT; }

	double drx = b->rx - rx, dry = b->ry - ry,
		dvx = b->vx - vx, dvy = b->vy - vy,
		dvdr = drx*dvx + dry*dvy;
	if (dvdr > 0) { return LIMIT; }

	double dvdv = dvx*dvx + dvy*dvy,
		drdr = drx*drx + dry*dry,
		r2 = b->r + r,
		d = dvdr*dvdr - dvdv * (drdr - r2*r2);
	if (d < 0) { return LIMIT; }
	return -(dvdr + sqrt(d)) / dvdv;
}

void Ball::bounceOff(Ball* b) {
	double drx = b->rx - rx, dry = b->ry - ry,
		dvx = b->vx - vx, dvy = b->vy - vy,
		dvdr = drx*dvx + dry*dvy,
		r2 = b->r + r,
		J = 2*b->m*m*dvdr / ((b->m + m)*r2),
		Jx = J*drx / r2,
		Jy = J*dry / r2;

	vx += Jx / m;
	vy += Jy / m;
	b->vx -= Jx / b->m;
	b->vy -= Jy / b->m;

	cnt += 1;
	b->cnt += 1;
}

double Ball::time2HitVWall() {
	if (vx > 0) { return (1.0 - rx - r) / vx; }
	if (vx < 0) { return (r - rx) / vx; }
	return LIMIT;
}

void Ball::bounceOffVWall() {
	vx = -vx;
	cnt += 1;
}

double Ball::time2HitHWall() {
	if (vy > 0) { return (1.0 - ry - r) / vy; }
	if (vy < 0) { return (r - ry) / vy; }
	return LIMIT;
}

void Ball::bounceOffHWall() {
	vy = -vy;
	cnt += 1;
}