#include <iostream>
#include <vector>
using namespace std;

//vector 插入擦出等复杂度高
class Solution{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int insert_index = 0;
		int i = 0;
		for (; i < n; i++) {
			while (insert_index < (m + i)) {
				if (nums1[insert_index] > nums2[i]) {
					nums1.insert(nums1.begin() + insert_index, nums2[i]);
					break;
				}
				else
					insert_index++;
			}
			if(insert_index >= (m + i)){
				nums1.insert(nums1.begin() + insert_index, nums2[i]);
				insert_index++;
			}
		}
		nums1.erase(nums1.begin()+m + i, nums1.end());
	}
};

class Solution1 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ia = m - 1, ib = n - 1, ic = n + m - 1;
		while (ia >= 0 && ib >= 0)
			nums1[ic--] = nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--];
		while (ib >= 0)
			nums1[ic--] = nums2[ib--];
	}
};

//int main() {
//	vector<int> a = { 2,5,7 };
//	vector<int> b = { 3,4,5,6 };
//	Solution s;
//	s.merge(a, 3, b, 4);
//	cin.get();
//	return 0;
//}