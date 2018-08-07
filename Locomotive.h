#ifndef _LOK_
#define _LOK_

#include "Vehicle.h"

class Locomotive : public Vehicle {
private:
	double vf;
	void Write(ostream& it) const override {
		it << "L(" << TotWeight() << "|" << vf << ")";
	}
public:
	Locomotive(double s, double v): Vehicle(s),vf(v){}
	double Power() const override { return vf; }
};


#endif
