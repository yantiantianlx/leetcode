#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		return searchRange(nums, 0, nums.size()-1, target);
	}
	vector<int> searchRange(vector<int>& nums, int begin, int end, int target) {
		vector<int> result = { -1, -1 };
		if (begin > end) return result;
		if (nums[begin] == nums[end] && nums[begin] == target) {
			result[0] = begin;
			result[1] = end;
			return result;
		}
		int mid = begin + (end - begin) / 2;
		if (nums[mid] > target) {
			return searchRange(nums, begin, mid - 1, target);
		}
		else if (nums[mid] < target) {
			return searchRange(nums, mid + 1, end, target);
		}
		else {
			//midÓÒÒÆ
			if (nums[mid] == nums[begin]) {
				while (nums[++mid] == target);
				return searchRange(nums, begin, mid - 1, target);
			}//mid×óÒÆ
			else {
				while (nums[--mid] == target);
				return searchRange(nums, mid + 1, end, target);
			}
		}
		return result;
	}
};

class Solution1 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
		const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
		if (l <= u && nums[l] == target) // not found
			return vector<int> { l, u };
		else
			return vector<int> { -1, -1};
	}
};
