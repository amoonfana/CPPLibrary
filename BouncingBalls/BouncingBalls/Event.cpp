#include "Event.h"

Event::Event(double t1, Ball* a1, Ball* b1) {
	t = t1;
	a = a1;
	b = b1;
	ca = a1 ? a1->cnt : -1;
	cb = b1 ? b1->cnt : -1;
}

bool Event::isValid() {
	if (a && a->cnt != ca) { return false; }
	if (b && b->cnt != cb) { return false; }
	return true;
}

bool Event::operator<(const Event b) const {
	return (t > b.t);
}