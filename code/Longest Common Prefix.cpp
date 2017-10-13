#include "Header.h"

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size()) return "";
		int j = 0;
		for (; j < strs[0].size(); j++){
			int i = 1;
			for (; i < strs.size(); i++){
				if (j < strs[i].size()){
					if (strs[i][j] != strs[0][j])
						return strs[0].substr(0, j);
				}
				else
					return strs[0].substr(0, j);
			}
		}
		return strs[0];
	}
};

//void main(){
//	vector<string> a = {"c","c"};
//	Solution s;
//	s.longestCommonPrefix(a);
//}

