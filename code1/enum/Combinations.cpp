#include <vector>
#include <iostream>
using namespace std;

class Solution1 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		if (n < k) return result;
		if (n == k && n >= 0) {
			vector<int> r = {};
			for (int i = 1; i <= n; i++)
				r.push_back(i);
			result.push_back(r);
			return result;
		}
		if (n > k && n > 0) {
			result = combine(n - 1, k);
			vector<vector<int>> res = combine(n - 1, k - 1);
			for (auto r : res) {
				r.push_back(n);
				result.push_back(r);
			}
		}
		
		return result;
	}
};

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> path;
		dfs(n, k, 1, 0, path, result);
		return result;
	}
	void dfs(int n, int k, int start, int cur, vector<int>& path, vector<vector<int>>& result) {
		if (cur == k) {
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; i++) {
			path.push_back(i);
			dfs(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
};

//int main() {
//	Solution s;
//	vector<vector<int>> a = s.combine(5, 3);
//	cin.get();
//	return 0;
//}