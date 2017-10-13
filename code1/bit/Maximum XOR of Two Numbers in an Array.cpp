#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int max = 0, mask = 0;
		for (int i = 31; i >= 0; i--) {
			mask |= 1 << i;
			unordered_set<int> s;
			for (auto num : nums)
				s.insert(num&mask);
			int t = max | 1 << i;
			for (auto pre : s) {
				if (s.find(pre ^ t) != s.end()) {
					max = t;
					break;
				}
			}
		}
		return max;
	}
};
int main() {
	vector<int> a = { 23,16,10 };
	Solution s;
	s.findMaximumXOR(a);
}