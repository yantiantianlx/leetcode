#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty()) return false;
		int reach = 0;
		for (int i = 0; i <= reach && reach < nums.size(); i++)
			reach = max(reach, nums[i] + i);
		if (reach >= nums.size()-1) return true;
		else return false;
	}
};

//int main() {
//	Solution s;
//	cout<<s.canJump(vector<int> {0,1});
//	return 0;
//}