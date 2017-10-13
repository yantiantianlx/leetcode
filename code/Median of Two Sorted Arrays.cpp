#include "Header.h"
#include <algorithm>

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int total = n1 + n2;
		//奇数中位数
		if (total & 0x01)
			return find_K(nums1.begin(), n1, nums2.begin(), n2, total / 2 + 1 );
		else
			return ( find_K(nums1.begin(), n1, nums2.begin(), n2, total / 2) +
					 find_K(nums1.begin(), n1, nums2.begin(), n2, total / 2 + 1) ) / 2.0;
	}

private:
	//寻找第K大的数
	double find_K(std::vector<int>::const_iterator nums1, int n1, std::vector<int>::const_iterator nums2, int n2, int k){
		if (n1 > n2) return find_K(nums2, n2, nums1, n1, k); //保证n1 < n2
		if (n1 == 0) return nums2[k - 1];
		if (k == 1)  return min(*nums1, *nums2); //终止条件

		int a = min(n1, k / 2); int b = k - a;
		if (nums1[a-1] < nums2[b-1])
			return find_K(nums1 + a, n1 - a, nums2, n2, k - a);
		else if (nums1[a-1] > nums2[b-1])
			return find_K(nums1, n1, nums2 + b, n2 - b, k - b);
		else
			return nums1[a-1];
	}

};