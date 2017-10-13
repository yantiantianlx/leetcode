#include <iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0) return 1.0 / Pow(x, -n);
		else return Pow(x, n);
	}
	double Pow(double x, int n) {
		if (n == 0)
			return 1;
		double val = Pow(x, n / 2);
		if (n % 2 == 0) return val*val;
		else return val * val * x;
	}
};