#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return INT_MIN;
		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < triangle[i].size(); j++) {
				triangle[i][j] = min(triangle[i][j]+ triangle[i+1][j],
					triangle[i][j] + triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
	}
};

//int main() {
//	vector<vector<int>> a = { {-1},{2,3},{1,-1,-3} };
//	Solution s;
//	cout << s.minimumTotal(a);
//	cin.get();
//	return 0;
//}