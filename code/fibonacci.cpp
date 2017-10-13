#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int fibonacci(int n) {
		if (n < 3) return (n-1);
		int a = 0;
		int b = 1;
		for (int i = 2; i < n; i++) {
			int temp = b;
			b = a + b;
			a = temp;
		}
	}
};

void main() {
	Solution s;
	s.fibonacci(10);
}
