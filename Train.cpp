#include "Train.h"
#include "Locomotive.h"
#include "Wagon.h"
#include "Errors.h"

Train & Train::operator+=(Vehicle * v)
{
	if (Check(v)) throw Err_Overload();
	arr += v;
	return *this;
}

bool Train::Check(Vehicle * v) const
{
	double uktez = 0, ukvf = 0;
	for (int i = 0; i < arr.Br(); i++) {
		uktez += arr[i].TotWeight();
		ukvf += arr[i].Power();
	}
	if (uktez + v->TotWeight() > ukvf + v->Power()) return true;
	return false;
}

ostream & operator<<(ostream & it, const Train & v)
{
	for (int i = 0; i < v.arr.Br(); i++) it << v.arr[i] << endl;
	return it;
}
