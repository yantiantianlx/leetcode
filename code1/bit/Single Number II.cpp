#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> b(32,0);
		int res = 0;
		for (int i = 0; i < 32; i++) {
			for (auto num : nums) {
				b[i] += num >> i & 1;
			}
			res |= (b[i] % 3 == 1) ? 1 << i : 0;
		}	
		return res;
	}
};