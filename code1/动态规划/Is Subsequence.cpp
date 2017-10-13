#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		auto i = s.begin();
		for (auto c : t)
			if (*i == c)
				i++;
		return i == s.end()?true:false;
	}
};