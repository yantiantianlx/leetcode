#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	vector<int> f;
	NumArray(vector<int> nums) {
		int n = nums.size();
		if (n <= 0) return;
		f = vector<int>(n,0);
		f[0] = nums[0];
		for(int i = 1; i < n; i++)
			f[i] = f[i - 1] + nums[i];
	}

	int sumRange(int i, int j) {
		if (i == 0) return f[j];
		return  f[j] - f[i-1];
	}
};