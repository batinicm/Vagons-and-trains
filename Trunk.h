#ifndef _SAND_
#define _SAND_

#include "Cargo.h"

class Trunk : public Cargo {
private:
	double a, b, c;
public:
	static const char VR = 'T';
	Trunk(double s, double p, double q, double r) : Cargo(s) { a = p; b = q; c = r; }
	char Type() const override { return VR; }
	Trunk* copy() const override { return new Trunk(*this); }
	double V() const override { return a*b*c; }
};

#endif
