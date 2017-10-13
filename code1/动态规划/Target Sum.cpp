#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		unordered_map<int, int> f;
		f[nums[0]] += 1;
		f[-nums[0]] += 1;
		for (int i = 1; i < n; i++) {
			unordered_map<int, int> now_f;
			for (auto j : f) {
				now_f[j.first + nums[i]] += j.second;
				now_f[j.first - nums[i]] += j.second;
			}
			f = now_f;
		}
		return f[S];
	}
};