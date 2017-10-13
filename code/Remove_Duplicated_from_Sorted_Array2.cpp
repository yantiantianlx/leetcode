#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int index = 2;
		for (int i = 2; i < nums.size(); i++)
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		return index;
	}
};

void main1(){
	vector<int> nums = { 1, 1, 1, 2 };
	Solution1 s;
	cout << s.removeDuplicates(nums) << endl;
	system("pause");

}