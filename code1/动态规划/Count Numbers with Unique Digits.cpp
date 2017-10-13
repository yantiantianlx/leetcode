#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		vector<int> f(n+1,0);
		f[0] = 1;
		for (int i = 1; i <= n; i++)
			f[i] = factorial(i) + f[i - 1];
		return f[n];
	}
	int factorial(int n) {
		int res = 1;
		for (int i = 0; i < n; i++) {
			if (i == 0 || i == 1)
				res *= 9;
			else
				res *= (9 - i + 1);
		}
		return res;
	}
};
