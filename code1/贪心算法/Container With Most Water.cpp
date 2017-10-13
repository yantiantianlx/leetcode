#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max_area = 0;
		while (right > left) {
			if (height[left] <= height[right]) {
				max_area = max(max_area, (right-left) * height[left]);
				left++;
			}
			else {
				max_area = max(max_area, (right - left) * height[right]);
				right--;
			}
		}
		return max_area;
	}
};