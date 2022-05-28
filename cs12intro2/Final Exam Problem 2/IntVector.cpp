#include <stdexcept>

using namespace std;

#include "IntVector.h"


// Place the implementation of your constructor here
IntVector::IntVector(int arr[], int beg, int end) {
	if ((end - beg) < 0) {
		cap = 0;
		sz = 0;
		data = new int[sz];
	}
	else {
		int range;
		range = (end - beg) + 1;
		sz = range;
		cap = range;
		data = new int[sz];
		int j = 0;
		for (int i = beg; i < end + 1; i++) {
			data[j] = arr[i];
			++j;
		}
	}
}






IntVector::~IntVector() {
	delete[] data;
}

unsigned IntVector::size() const { return sz; }
unsigned IntVector::capacity() const { return cap; }
bool IntVector::empty() const { return sz == 0; }

const int & IntVector::at(unsigned index) const {
	if (index < sz) {
	   return data[index];
	}
	else {
	   throw out_of_range("IntVector::at_range_check");
	}
}

int & IntVector::at(unsigned index)
{
	if (index < sz) {
	   return data[index];
	}
	else {
	   throw out_of_range("IntVector::at_range_check");
	}
}
