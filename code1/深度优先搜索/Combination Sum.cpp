#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		dfs(nums, target, path, result);
		return result;
	}
private:
	void dfs(vector<int> &nums, int target, vector<int>& path, vector<vector<int>>& result) {
		if (target == 0) {
			result.push_back(path);
			return;
		}
		for (auto num : nums) {
			if (num > target) return;
			if (path.size() > 0 && num < path.back()) continue;//元素可重复使用，2,2,3与3,2,2一样，保持升序
			path.push_back(num);
			dfs(nums, target - num, path, result);
			path.pop_back();
		}
	}
};

//int main() {
//	vector<int> a = { 2,3,6,7 };
//	Solution s;
//	
//	vector<vector<int>> b = s.combinationSum(a, 7);
//	return 0;
//}