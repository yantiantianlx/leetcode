#include "Header.h"

class Solution {
public:
	int search(vector<int>& nums, int target) {
		auto first = nums.begin();
		auto last = nums.end();
		while (first < last){
			auto mid = first + ( last - first) / 2;
			if (*mid == target)
				return (mid - nums.begin());
			if (*first <= *mid){
				if (*first <= target && target < *mid)
					last = mid;
				else
					first = mid + 1;
			}
			else{
				if (*mid < target && target <= *(last -1 ))
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;		
	}
};

