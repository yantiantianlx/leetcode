#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;
		int begin = 1, end = x;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			int val = (x / mid);
			if (val == mid)
				return mid;
			else if (val > mid)
				begin = mid + 1;
			else
				end = mid - 1;
		}
		return end;
	}
};

int main() {
	Solution s;
	s.mySqrt(3);
}