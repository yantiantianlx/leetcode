#include "Header.h"
#include <algorithm>

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//边界问题很重要
		vector<vector<int>> result;
		if (nums.size() < 3) return result;

		int target = 0;
		sort(nums.begin(), nums.end());
		auto last = nums.end();
		for (auto i = nums.begin(); i < last - 2; i++){
			if (i > nums.begin() && *i == *(i - 1)) continue;
			auto j = i + 1;
			auto k = last - 1;
			while (j < k){
				if ((*i + *j + *k) < target){
					j++;
					while (*j == *(j - 1) && j < k) j++;
				}
				else if ((*i + *j + *k) > target){
					k--;
					while (*k == *(k + 1) && j < k) k--;
				}
				else{
					result.push_back({*i, *j, *k});
					j++;
					k--;
					while (*j == *(j - 1) && j < k) j++;
					while (*k == *(k + 1) && j < k) k--;
				}
			}
		}
		return result;
	}
};

