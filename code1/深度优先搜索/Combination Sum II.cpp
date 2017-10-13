#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> path;
		dfs(candidates, target, 0, path, result);
		return result;
	}

private:
	void dfs(vector<int>& nums, int target, int start, vector<int>& path, vector<vector<int>>& result) {
		if (target == 0) {
			result.push_back(path);
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			if (i != start && nums[i] == nums[i - 1]) continue;//数组中有两个1，则前一个1得到1/7和后一个1得到1/7重复
			if (nums[i] > target) return;
			path.push_back(nums[i]);
			dfs(nums, target - nums[i], i + 1, path, result);
			path.pop_back();
		}
	}
};
//
//int main() {
//	vector<int> a = { 10,1,2,7,6,1,5 };
//	Solution s;
//	vector<vector<int>> b = s.combinationSum2(a, 8);
//	return 0;
//}