#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> f(target+1, 0);
		for (int i = 1; i <= target; i++) {
			for (auto num : nums) {
				if (i - num > 0)
					f[i] += f[i - num];
				else if (i - num == 0)
					f[i] += 1;
			}
		}
		return f[target];
	}
};