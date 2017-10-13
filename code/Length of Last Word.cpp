#include "Header.h"
#include <algorithm>
//#include <functional>
class Solution {
public:
	int lengthOfLastWord(string s) {
		auto fist_is = find_if(s.rbegin(), s.rend(), ::isalpha);
		auto fist_not = find_if_not(fist_is, s.rend(), ::isalpha);
		return fist_not - fist_is;
	}
};

//void main(){
//	string a = " ";
//	Solution s;
//	int n = s.lengthOfLastWord(a);
//}