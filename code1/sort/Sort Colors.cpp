#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0, white = 0, blue = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				red++;
				nums[red - 1] = 0;
				if(white > 0)
					nums[red + white - 1] = 1;
				if(blue > 0)
					nums[red + white + blue - 1] = 2;
			}
			else if (nums[i] == 1) {
				white++;
				nums[red + white - 1] = 1;
				if (blue > 0)
					nums[red + white + blue - 1] = 2;
			}
			else {
				blue++;
				nums[red + white + blue - 1] = 2;
			}
				
		}
	}
};

//int main() {
//	vector<int> a = { 0,0 };
//	Solution s;
//	s.sortColors(a);
//	return 0;
//}