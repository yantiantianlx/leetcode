#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return subsets(nums.begin(), nums.end());
	}
	template<typename iterator>
	vector<vector<int>> subsets(iterator begin, iterator end) {
		vector<vector<int>> result;
		if (begin == end) {
			result.push_back(vector<int>{});
			return result;
		}
		vector<vector<int>> res = subsets(begin, end - 1);
		result = res;
		for (auto r : res) {
			//result.push_back(r);
			r.push_back(*(end - 1));
			result.push_back(r);
		}
		return result;
	}
};

//int main() {
//	vector<int> a = {1};
//	Solution s;
//	s.subsets(a);
//	return 0;
//}