#pragma once

#define LIMIT 10000
#define TimeTick 2.0
#define PI 3.1415926535

class Ball {
public:
	double rx, ry;
	double vx, vy;
	double r;
	double m;
	int cnt;

	Ball();
	Ball(double rx1, double ry1, double vx1, double vy1, double r1, double m1);

	void move(double dt);
	double time2Hit(Ball* b);
	void bounceOff(Ball* b);
	double time2HitVWall();
	void bounceOffVWall();
	double time2HitHWall();
	void bounceOffHWall();
};