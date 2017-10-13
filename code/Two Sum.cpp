#include "Header.h"
#include <unordered_map>

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
			m[nums[i]] = i;
		for (int i = 0; i < nums.size(); i++){
			int gap = target - nums[i];
			if (m.find(gap) != m.end() && m[gap] > i){
				result.push_back(i);
				result.push_back(m[gap]);
			}
		}
		/*错误写法*/
		/*[3,3]不满足 , m只有一个*/
		/*for (auto i : nums){
			int gap = target - i;
			if (m.find(gap) != m.end() && m[gap] > m[i]){
				result.push_back(m[i]);
				result.push_back(m[gap]);
			}
		}*/
		return result;
	}
};

void main10(){
	vector<int> num = { 3, 3};
	Solution s;
	num = s.twoSum(num, 6);
	system("pause");
}