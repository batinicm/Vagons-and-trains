#ifndef _VAGON_
#define _VAGON_

#include "Vehicle.h"
#include "TemplateArray.h"
#include "Trunk.h"
#include "Barrel.h"

class Wagon : public Vehicle {
private:
	Array<Cargo> arr;
	void Write(ostream& it) const override;
public:
	Wagon(double s, int k) : Vehicle(s), arr(k) {}
	Wagon& operator+=(Cargo* t) {
		arr += t;
		return *this;
	}
	double Power() const override { return 0; }
	double TotWeight() const override;
};

#endif
