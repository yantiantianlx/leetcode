#include "Header.h"
#include <algorithm>
#include <functional>
class Solution {
public:
	string countAndSay(int n) {
		if (n < 1) return "";
		string s = "1";
		while(--n){
			for (int i = 0; i < s.size(); i = i + 2){
				int next = find_if_not(s.begin() + i, s.end(), bind2nd(equal_to<int>(), s[i])) - s.begin();
				//存在插入，要用int i 而不是iterator因为长度太长，起始iterator变了
				s.insert(s.begin() + i, next - i + '0');
				s.erase(s.begin() + i + 1, s.begin() + next);
			}
		}
		return s;
	}
};

//void main(){
//	Solution s;
//	s.countAndSay(10);
//}