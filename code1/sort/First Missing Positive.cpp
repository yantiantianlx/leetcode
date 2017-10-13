#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for(int i = 0; i < nums.size();){
			if (nums[i] > 0 && (nums[i] != i + 1 ) &&
				nums[i] - 1 < nums.size() && nums[nums[i] - 1] != nums[i])
					swap(nums[i], nums[nums[i] - 1]);
			else
				i=i+1;
		}
		int i = 0;
		for (; i < nums.size(); i++)
			if (nums[i] != i + 1)
				break;
		return i + 1;
	}
};

//int main() {
//	vector<int> a = {1,1};
//	Solution s;
//	cout << s.firstMissingPositive(a) << endl;
//	cin.get();
//	return 0;
//}