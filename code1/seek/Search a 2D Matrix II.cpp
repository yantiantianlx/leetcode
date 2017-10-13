#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int m = matrix.size();
		if (matrix[0].empty()) return false;
		int n = matrix[0].size();
		int i = 0, j = 0;
		while (i < m && j < n) {
			if (matrix[i][j] == target)
				return true;
			if (matrix[i][j] < target) {
				if(j < n-1)
					j++;
				else {
					j = 0;
					i++;
				}
			}
			else if (matrix[i][j] > target) {
				i++;
				j = 0;
			}
		}
		return false;
	}
};

int main() {
	vector<vector<int>> a = { {-5} };
	Solution s;
	cout<<s.searchMatrix(a, 2);
	cin.get();
}