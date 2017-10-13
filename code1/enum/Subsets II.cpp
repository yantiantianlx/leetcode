#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution1 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
		vector<vector<int>> res = subsets(begin, end-1);
		//多判断一下是否插入
		for (auto r = res.begin(); r < res.end() - 1;r++){
			result.push_back(*r);
			(*r).push_back(*(end-1));
			//判断r与r+1是否相同
			if(*r != *(r+1) )
				result.push_back(*r);
		}
		result.push_back(*(res.end()-1));
		(*(res.end() - 1)).push_back(*(end - 1));
		result.push_back(*(res.end() - 1));
		return result;
	}
};

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result = { {} };
		int pre_num = 0;
		for (int i = 0; i < nums.size(); i++) {
			int n = result.size();
			for (int j = 0; j < n; j++) {
				if (i == 0 || nums[i] != nums[i - 1] || j >= pre_num) {
					result.push_back(result[j]);
					result.back().push_back(nums[i]);
				}
			}
			pre_num = n;
		}
		return result;
	}
};

//int main() {
//	vector<int> a = { 1,2,2 };
//	Solution s;
//	vector<vector<int>> b = s.subsetsWithDup(a);
//	cin.get();
//	return 0;
//}