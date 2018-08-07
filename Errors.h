#ifndef _GRESKE_
#define _GRESKE_

#include <iostream>
using namespace std;

class Err_Full{};
inline ostream& operator<<(ostream& it, const Err_Full& g) {
	it << "*** Array full!***\n";
	return it;
}

class Err_Index {};
inline ostream& operator<<(ostream& it, const Err_Index& g) {
	it << "*** Index out of range!***\n";
	return it;
}

class Err_Overload {};
inline ostream& operator<<(ostream& it, const Err_Overload& g) {
	it << "*** Train overloaded! ***\n";
	return it;
}

#endif
