#include "Header.h"
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, bool> m;
		for (auto i : nums) //C++ 取值方式
			m[i] = false;
		int longest = 0;
		for (auto i : nums){
			if (m[i]) continue;
			int length = 1;
			m[i] = true;
			for (int j = i + 1; m.find(j) != m.end(); j++){
				m[j] = true;
				length++;
			}
			for (int j = i - 1; m.find(j) != m.end(); j--){
				m[j] = true;
				length++;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};