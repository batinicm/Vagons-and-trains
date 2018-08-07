#ifndef _VOZ_
#define _VOZ_

#include "Locomotive.h"
#include "Wagon.h"

class Train {
private:
	Array<Vehicle> arr;
public:
	explicit Train(int k): arr(k){}
	Train(const Train& v) = delete;
	Train& operator=(const Train& v) = delete;
	Train& operator+=(Vehicle* v);
	int NumOfVehicles() const { return arr.Br(); }
	bool Check(Vehicle* v) const;
	friend ostream& operator<<(ostream& it, const Train& v);
};

#endif
