#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) return 0;
		heights.push_back(-1);
		stack<int> box;
		int maxHeight = 0, nowHeight = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (!box.empty() && heights[i] < heights[box.top()]){
				int index = box.top();
				box.pop();
				nowHeight =  heights[index]*(box.empty()? i: i-box.top()-1);
				maxHeight = max(maxHeight, nowHeight);
				
			}
			box.push(i);
		}
		return maxHeight;
	}
};

//int main() {
//	vector<int> a = { 3,6,5,7,4,8,1,0 };
//	Solution s;
//	cout<<s.largestRectangleArea(a);
//	cin.get();
//	return 0;
//}