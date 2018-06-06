#pragma once
#include "Ball.h"

class Event {
public:
	double t;
	Ball *a, *b;
	int ca, cb;

	Event(double t, Ball* a, Ball* b);
	bool isValid();
	bool operator<(Event b) const;
};