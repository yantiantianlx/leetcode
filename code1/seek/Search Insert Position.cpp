#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto lower = lower_bound(nums.begin(), nums.end(), target);
		return lower - nums.begin();
	}
	template<typename iterator>
	iterator lower_bound(iterator begin, iterator end, int target) {
		while (begin < end) {
			auto mid = begin + (end - begin) / 2;
			if (*mid < target)
				begin = mid + 1;
			else if (*mid > target)
				end = mid;
			else
				return mid;
		}
		return begin;
	}
};

//int main() {
//	vector<int> a = {1,3,5,6};
//	Solution s;
//	cout << s.searchInsert(a,0) << endl;
//	cin.get();
//	return 0;
//}