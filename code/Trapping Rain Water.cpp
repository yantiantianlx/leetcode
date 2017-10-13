#include "Header.h"

class Solution {
public:
	int trap(vector<int>& height) {
		int water = 0;
		int peak = 0;
		int p_index = 0;
		for (int i = 0; i < height.size(); i++)
			if (height[i] > peak){
				peak =  height[i];
				p_index = i;
			}
			
		int top = 0;
		for (int i = 0; i < p_index; i++){
			if (height[i] > top)
				top = height[i];
			else
				water += top - height[i];
		}
		top = 0;
		for (int i = height.size()-1; i > p_index; i--){
			if (height[i] > top)
				top = height[i];
			else
				water += top - height[i];
		}
		return water;

	}
};