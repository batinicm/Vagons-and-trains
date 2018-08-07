#include "Barrel.h"
#include "Trunk.h"
#include "Locomotive.h"
#include "Wagon.h"
#include "Train.h"


int main() {
	string ns;
	try {
		Train tr(3);
		tr += new Locomotive(200, 3000);
		Wagon* vag = new Wagon(100, 5);
		*vag += new Trunk(3, 2, 1, 3);
		*vag += new Barrel(2,2,4);
		tr += vag;
		vag = new Wagon(150, 10);
		*vag += new Trunk(4,2,10,3);
		*vag += new Barrel(6,3,8);
		tr += vag;
		cout << tr;
	}
	catch (Err_Overload g) { cout << g; }
	catch (Err_Full g) { cout << g; }
}
