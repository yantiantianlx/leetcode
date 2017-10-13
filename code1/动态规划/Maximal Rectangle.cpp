#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int row = matrix.size();
		if (matrix[0].empty()) return 0;
		int col = matrix[0].size();
		vector<int> height(col, 0);
		int maxArea = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i > 0 && matrix[i][j] == '1')
					height[j] = height[j] + 1;
				else
					height[j] = matrix[i][j] == '1' ? 1 : 0;
			}
			maxArea = max(maxArea, largestRectangleArea(height));
		}
		return maxArea;
	}
	int largestRectangleArea(vector<int> height) {
		stack<int> box;
		height.push_back(0);
		int maxHeight = 0;
		for (int i = 0; i < height.size(); i++) {
			while (!box.empty() && height[i] < height[box.top()]) {
				int index = box.top();
				box.pop();
				int nowheight = height[index] * (box.empty()? i : i-box.top()-1);
				maxHeight = max(maxHeight, nowheight);
			}
			box.push(i);
		}
		while (!box.empty())
			box.pop();
		return maxHeight;
	}
};

//int main() {
//	vector<vector<char>> a = {{ '1', '0', '1', '0', '0' },
//	{'1', '0', '1', '1', '1'},
//	{'1', '1', '1', '1', '1'},
//	{'1', '0', '0', '1', '0'} };
//	Solution s;
//	cout<<s.maximalRectangle(a);
//	cin.get();
//	return 0;
//}