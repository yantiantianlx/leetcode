#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) return 0;
		int m = obstacleGrid.size();
		if (obstacleGrid[0].empty()) return 0;
		int n = obstacleGrid[0].size();
		vector<vector<int>> f(m, vector<int>(n, 0));
		if (obstacleGrid[0][0] == 0)
			f[0][0] = 1;
		else return 0;
		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (obstacleGrid[i][j] == 1)
					f[i][j] = 0;
				else{
					if (i == 0 && j > 0)
						f[i][j] = f[i][j - 1];
					else if (i > 0 && j == 0)
						f[i][j] = f[i-1][j];
					else if(i > 0 && j > 0)
						f[i][j] = f[i - 1][j] + f[i][j - 1];
				}
			}
		return f[m-1][n-1];
	}
};

//int main() {
//	vector<vector<int>> board = { 
//		{0,0,0},{0,1,0},{0,0,0} };
//	Solution s;
//	cout<<s.uniquePathsWithObstacles(board);
//	cin.get();
//	return 0;
//
//}