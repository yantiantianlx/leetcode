#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_l = 0;
		int index = 0;
		int last[26];
		for (int i = 0; i < s.size(); )
			if (i != 0) {
				if (last[s[i] - 'a'] != 0) {
					last[s[i] - 'a'] = i;
					index++;
					i++;
				}
				else {
					max_l = max(max_l, index);
					index = 0;
					i = last[s[i]] + 1;
					memset(last, 0, 255 * sizeof(int));
				}
			}
		max_l = max(max_l, index);
		return max_l;
	}
};

//int main() {
//	//qpxrjxkltzyx
//	Solution s;
//	cout << s.lengthOfLongestSubstring("abcabcbb");
//	cin.get();
//	return 0;
//}