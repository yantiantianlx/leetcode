#include "Header.h"
//#include <algorithm>
#include <functional>
#include <algorithm>

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//�Ӻ���ǰ�������ĵݼ�����
		auto pivot = nums.rbegin() + 1;
		while (pivot != nums.rend() && *pivot >= *prev(pivot))
			pivot++;
		//����Ϊ�ݼ���ת
		if (pivot == nums.rend()){
			reverse(nums.begin(), nums.end());
			return;
		}

		//����pivot�����ݼ������е�һ����pivot���ֵ
		auto x = find_if(nums.rbegin(), pivot, bind1st(less<int>(), *pivot));
		swap(*pivot, *x);
		//�ݼ���Ϊ����
		reverse(nums.rbegin(), pivot);
		
	}
};

