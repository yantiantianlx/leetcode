#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.begin() == nums.end())
			return result;
		vector<int> a = nums ;
		result.push_back(a);
		a = next_permute(a);
		while (a != nums) {
			result.push_back(a);
			a = next_permute(a);
		}
		return result;
	}
	vector<int> next_permute(vector<int> nums) {
		auto rbegin = nums.rbegin();
		auto rend = nums.rend();

		////’“µΩµ›ºı–Ú¡–iterator
		auto cur = rbegin;
		//while (cur < (rend - 1) && *cur <= *next(cur))
		while (cur < (rend - 1) && *cur <= *next(cur))
			cur = next(cur);

		cur = next(cur) <= rend ? next(cur) : rend;
		if( cur != rend){
			auto next_val = find_if(rbegin, cur, bind1st(less<int>(), *cur));
			swap(*next_val, *cur);
		}
		reverse(rbegin, cur);
		return nums;
	}
};

//int main() {
//	vector<int> a = { 1,1,2 };
//	Solution s;
//	vector<vector<int>> b = s.permute(a);
//	cin.get();
//	return 0;
//}