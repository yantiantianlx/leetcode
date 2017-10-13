#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) return INT_MAX;
		int row = grid.size();
		int col = grid[0].size();
		if (col == 0) return INT_MAX;
		
		for(int i = 1; i < row; i++)
			grid[i][0] += grid[i-1][0];
		for(int j = 1; j < col; j++)
			grid[0][j] += grid[0][j - 1];
		for (int i = 1; i < row; i++)
			for (int j = 1; j < col; j++)
				grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
		
		return grid[row - 1][col - 1];
	}
};

//int main() {
//	vector<vector<int>> a = { {1} };
//	Solution s;
//	s.minPathSum(a);
//}