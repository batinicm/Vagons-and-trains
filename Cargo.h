#ifndef _TERET_
#define _TERET_

#include <iostream>
using namespace std;

class Cargo {
private:
	static int gId;
	int id = ++gId;
	double sigma;
public:
	Cargo(double s): sigma(s){}
	Cargo(const Cargo& t) { sigma = t.sigma; }
	virtual ~Cargo(){}
	Cargo& operator=(const Cargo& t) {
		sigma = t.sigma;
		return *this;
	}
	virtual char Type() const = 0;
	virtual Cargo* copy() const = 0;
	virtual double V() const = 0;
	double Weight() const { return sigma*V(); }
private:
	void Write(ostream& it) const {
		it << Type()<< id;
	}
	friend ostream& operator<<(ostream& it, const Cargo& t) {
		t.Write(it);
		return it;
	}
};


#endif
