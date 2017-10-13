#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int begin = 0, end = rows * cols - 1;
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			int val = matrix[mid / cols][mid % cols];
			if (val > target) {
				end = mid - 1;
			}
			else if(val < target){
				begin = mid + 1;
			}
			else
				return true;
		}
		return false;
	}
};

//int main() {
//	vector<vector<int>> a = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
//	Solution s;
//	cout<<s.searchMatrix(a, 3);
//	cin.get();
//	return 0;
//}