#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return INT_MIN;
		int n = nums.size();
		int f = nums[0];
		int fmax = f;
		for (int i = 1; i < n; i++) {
			f = max(f + nums[i], nums[i]);
			fmax = max(f,fmax);
		}
	
		return fmax;
	}
};

//int main() {
//	vector<int> a = { -2,1,-3,4,-1,2,1,-5,4 };
//	Solution s;
//	cout<<s.maxSubArray(a);
//	cin.get();
//	return 0;
//}