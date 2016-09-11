#include <iostream>
#include <algorithm>

using namespace std;


/*
gcm(a,a) = a
gcm(a,b) = gcm(b,a)
gcm(a,b) = gcm(a,a+b)

b<a => gcm(a-b,b)

*/


//! greatest common divisor
int gcm0(int a, int b) {
	while (a != b) {
		if (b < a) a = a - b;
		else       b = b - a;
	}

	return a;
}

//! greatest common divisor
int gcm1(int a, int b) {
	while (a != b) {
		while (b < a) a = a - b;
		std::swap(a, b);
	}

	return a;
}

//! greatest common divisor
int gcm2(int a, int b) {
	while (b != 0) {
		a = a % b;
		std::swap(a, b);
	}

	return a;
}





int main(void) {
	int a = 1071;
	int b = 1029;
//	int gcm = gcm0(a, b);
//	int gcm = gcm1(a, b);
	int gcm = gcm2(a, b);

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "gcm:" << gcm << endl;

	return 0;
}