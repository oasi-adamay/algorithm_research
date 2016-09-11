#include <iostream>
#include <algorithm>

using namespace std;


/*
gcd(a,a) = a
gcd(a,b) = gcd(b,a)
gcd(a,b) = gcd(a,a+b)

b<a => gcd(a-b,b)

*/


//! greatest common divisor
int gcd0(int a, int b) {
	while (a != b) {
		if (b < a) a = a - b;
		else       b = b - a;
	}

	return a;
}

//! greatest common divisor
int gcd1(int a, int b) {
	while (a != b) {
		while (b < a) a = a - b;
		std::swap(a, b);
	}

	return a;
}

//! greatest common divisor
int gcd2(int a, int b) {
	while (b != 0) {
		a = a % b;
		std::swap(a, b);
	}

	return a;
}


//! greatest common divisor
// stein gcd
int gcd3(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == 0) return b;
	if (b == 0) return a;

	int d_a = 0;
	while (!(a & 1)) {
		a >>= 1;
		d_a++;
	}

	int d_b = 0;
	while (!(b & 1)) {
		b >>= 1;
		d_b++;
	}

	// odd(a) && odd(b)
	while (a != b) {
		if (b > a) swap(b, a);
		a = a - b;
		do a >>= 1;
		while (!(a & 1));
	}

	return a << min(d_a,d_b);
}






int main(void) {
//	int a = 1071;
//	int b = 1029;

	int k = rand();
	int a = k*rand();
	int b = k*rand();

	int _gcd0 = gcd0(a, b);
	int _gcd1 = gcd1(a, b);
	int _gcd2 = gcd2(a, b);
	int _gcd3 = gcd3(a, b);

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "gcd0:" << _gcd0 << endl;
	cout << "gcd1:" << _gcd1 << endl;
	cout << "gcd2:" << _gcd2 << endl;
	cout << "gcd3:" << _gcd3 << endl;


	return 0;
}