#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		diff &= -diff;
		int sum1=0, sum2=0;
		for (auto num : nums) {
			if (num & diff) sum1 ^= num;
			else sum2 ^= num;
		}
		return vector<int>{sum1, sum2};
	}
};
