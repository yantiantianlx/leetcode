#include "Header.h"
#include <algorithm>

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int index = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != val)
				nums[index++] = nums[i];
		return index;

		//return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};