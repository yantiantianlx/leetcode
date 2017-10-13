#include "Header.h"

class Solution {
public:
	int climbStairs(int n) {
		//double s = sqrt(5);
		//return floor( ( pow( (1+s)/2, n+1) + pow( (1-s)/2,n+1)) / s + 0.5);
		//return floor( ( pow( (1+s)/2, n+1) - pow( (1-s)/2,n+1)) / s + 0.5);

		int pre = 0;
		int cur = 1;
		for (int i = 0; i < n; i++){
			int tmp = cur;
			cur += pre;
			pre = tmp;
		}
		return cur;
	}
};

