#include "Header.h"
#include <algorithm>

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//abs(INT_MAX - (-1)) = -(INT_MAX+1)
		int min_gap = INT_MAX;
		int result = INT_MAX;
		if (nums.size() < 2) return result;
		sort(nums.begin(), nums.end());
		for (auto i = nums.begin(); i < nums.end() - 2; i++){
			auto j = i + 1;
			auto k = nums.end() - 1;
			while (j < k){
				int sum = *i + *j + *k;
				int gap = abs(sum - target);
				if (gap < min_gap){
					result = sum;
					min_gap = gap;
				}
					
				if(sum < target)	j++;
				else k--;
			}
		}
		return result;
	}
};

