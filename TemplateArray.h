#ifndef _NIZ_
#define _NIZ_

#include <iostream>
#include "Errors.h"
using namespace std;

template <typename T>
class Array {
private:
	T** arr;
	int cap, num;
	void copy(const Array& n);
	void del();
	void move(Array& n) {
		arr = n.arr;
		cap = n.cap;
		num = n.num;
		n.arr = nullptr;
	}
public:
	explicit Array(int k=10);
	Array(const Array& n) { copy(n); }
	Array(Array&& n) { move(n); }
	~Array() { del(); }
	Array& operator=(const Array& n) {
		if (this != &n) {
			del();
			copy(n);
		}
		return *this;
	}
	Array& operator=(Array&& n) {
		if (this != &n) {
			del();
			move(n);
		}
		return *this;
	}
	Array& operator+=(T* t) {
		if (num == cap) throw Err_Full();				
		arr[num++] = t;
		return *this;
	}
	int Br() const { return num; }
	T& operator[](int x) {
		if (x<0 || x>num - 1) throw Err_Index();
		return *arr[x];
	}
	const T& operator[](int x) const {
		return const_cast<Array&>(*this)[x];
	}
};

#endif

template<typename T>
inline Array<T>::Array(int k){
	arr = new T*[cap = k];
	for (int i = 0; i < cap; i++) arr[i] = nullptr;
	num = 0;
}

template<typename T>
void Array<T>::copy(const Array& n) {
	arr = new T*[cap = n.cap];
	num = n.num;
	for (int i = 0; i < cap; i++) arr[i] = n.arr[i]->copy();
}

template <typename T>
void Array<T>::del() {
	for (int i = 0; i < num; i++) {
		delete arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;						
	cap = num = 0;
}
