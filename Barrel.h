#ifndef _BURE_
#define _BURE_

#include "Cargo.h"

class Barrel : public Cargo {
private:
	double r, h;
public:
	static const char VR = 'B';
	Barrel(double s, double p, double v) : Cargo(s) { r = p; h = v; }
	char Type() const override { return VR; }
	double V() const override { return r*r*3.14159*h; }
	Barrel* copy() const override { return new Barrel(*this); }
};

#endif
