#include "Header.h"

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0;
		int two = 0;
		int three = 0;
		for (auto i : nums){
			two |= one & i;
			one ^= i;
			three = ~(one & two);
			one &= three;
			two &= three;
		}
		return one | two;
	}
};