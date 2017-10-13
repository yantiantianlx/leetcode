#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int sum = n*(n + 1) / 2;
		int sum_num = 0;
		for (auto i : nums)
			sum_num += i;
		return sum - sum_num;
	}
};