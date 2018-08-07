#ifndef _VOZILO_
#define _VOZILO_

#include <iostream>
using namespace std;

class Vehicle {
private:
	double weight;
	virtual void Write(ostream& it) const = 0;
	friend ostream& operator<<(ostream& it, const Vehicle& v) {
		v.Write(it);
		return it;
	}
public:
	explicit Vehicle(double s): weight(s){}
	Vehicle(const Vehicle& v) = delete;
	virtual ~Vehicle(){}
	Vehicle& operator=(const Vehicle& v) = delete;
	virtual double TotWeight() const { return weight; }
	virtual double Power() const = 0;
};

#endif
