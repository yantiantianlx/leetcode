#include "Header.h"

class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		for (int i = 0; i < n; i++)
			s[i] += i + 1;
		int base = factorial(n - 1);
		k--;
		string result;
		for (int i = n - 1; i >= 1; k %= base, base /= i, i--){
			auto a = s.begin() + k / base;
			result.push_back(*a);
			//删除一个或删一个范围
			s.erase(a);
		}
		result.push_back(s[0]);

		return result;

	}
private:
	int factorial(int n){
		int f = 1;
		for (int i = 1; i <= n; i++)
			f *= i;
		return f;
	}
};
