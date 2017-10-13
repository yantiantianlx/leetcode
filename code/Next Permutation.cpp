#include "Header.h"
//#include <algorithm>
#include <functional>
#include <algorithm>

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//从后向前找找最大的递减序列
		auto pivot = nums.rbegin() + 1;
		while (pivot != nums.rend() && *pivot >= *prev(pivot))
			pivot++;
		//数组为递减则翻转
		if (pivot == nums.rend()){
			reverse(nums.begin(), nums.end());
			return;
		}

		//交换pivot与最大递减数列中第一个比pivot大的值
		auto x = find_if(nums.rbegin(), pivot, bind1st(less<int>(), *pivot));
		swap(*pivot, *x);
		//递减改为递增
		reverse(nums.rbegin(), pivot);
		
	}
};

