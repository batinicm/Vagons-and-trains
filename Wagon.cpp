#include "Wagon.h"
#include "Barrel.h"
#include "Trunk.h"

void Wagon::Write(ostream & it) const
{
	it << "V(" << TotWeight() << "|";
	for (int i = 0; i < arr.Br(); i++) {
		it << arr[i];
		i == arr.Br() - 1 ? it << ")" : it << ",";
	}
}

double Wagon::TotWeight() const
{
	double t = Vehicle::TotWeight();
	for (int i = 0; i < arr.Br(); i++) t += arr[i].Weight();
	return t;
}

