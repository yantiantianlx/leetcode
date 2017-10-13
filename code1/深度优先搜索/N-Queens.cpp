#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		if (n < 1) return result;
		vector<int> row_state(n,0);
		get_solution(n, 0, result, row_state);
		return result;
	}

	void get_solution(int n, int row, vector<vector<string>>& result, vector<int>& row_state) {
		if (row == n) {
			vector<string> res;
			for (int i = 0; i < row_state.size(); i++) {
				string s = "";
				for (int j = 0; j < n; j++) {
					if (row_state[i] == j)
						s += "Q";
					else
						s += ".";
				}
				res.push_back(s);
			}
			result.push_back(res);
			return;
		}
		for (int j = 0; j < n ; j++) {
			row_state[row] = j;
			if (is_valid(row_state, row)) {
				get_solution(n, row + 1, result, row_state);
			}
		}
	}

	bool is_valid(vector<int>& row_state, int row) {
		for (int i = 0; i < row; i++) {
			if (row_state[row] != row_state[i] &&
				(abs(i - row) != abs(row_state[i] - row_state[row])));
			else return false;
		}
		return true;
	}
};
//
//int main() {
//	Solution s;
//	vector<vector<string>> a = s.solveNQueens(4);
//	cin.get();
//	return 0;
//}