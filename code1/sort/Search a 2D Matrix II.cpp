#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int rows = matrix.size();
		if (matrix[0].empty()) return false;
		int cols = matrix[0].size();

		int row = 0, col = cols - 1;
		while (row < rows && col >= 0) {
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] > target)
				col--;
			else {
				row++;
			}
		}
		return false;
	}
};

//int main() {
//	vector<vector<int>> a = {
//		{-5} };
//
//	Solution s;
//	cout<<s.searchMatrix(a, 6);
//	cin.get();
//	return 0;
//}