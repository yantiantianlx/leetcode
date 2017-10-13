#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if (n <= 2) return 0;
		int error = A[2] - A[1] == A[1] - A[0] ? 1 : 0;
		int result = error;
		for (int i = 3; i < n; i++) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				error++;
			else
				error = 0;
			result += error;
		}
		return result;
	}
};