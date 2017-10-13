#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int sum = 0;
		int n = nums.size();
		for (int i = 0; i < 32; i++) {
			int num_one = 0;
			int mask = 1 << i;
			for (auto num : nums)
				if (num&mask)
					num_one++;
			sum += num_one *(n - num_one);
		}
		return sum;
	}
};
