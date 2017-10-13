#include "Header.h"
#include <unordered_map>

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> m = { { 'M', 1000 }, { 'D', 500 },
		{ 'C', 100 }, { 'L', 50 }, { 'X', 10 }, { 'V', 5 }, { 'I', 1 } };
		int result = 0;
		auto i = s.begin();
		for (; i < s.end() - 1;){
			if ( m[*i] < m[*(i + 1)]){
				result += m[*(i + 1)] - m[*i];
				i += 2;
			}
			else{
				result +=  m[*i];
				i++;
			}	
		}
		if (i == s.end() - 1) result += m[*i];
		return result;
	}
};

//void main(){
//	Solution s;
//	s.romanToInt("DCXXI");
//}