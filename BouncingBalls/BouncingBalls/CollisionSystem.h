#pragma once
#include <queue>
#include "Event.h"

using namespace std;

class CollisionSystem {
public:
	priority_queue<Event> pq;
	double t;
	vector<Ball> bs;

	CollisionSystem();
	CollisionSystem(vector<Ball> bs);

	void draw();
	void predict(Ball* a);
	void simulate();
};