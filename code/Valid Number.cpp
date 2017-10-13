#include "Header.h"
#include <array>

class Solution {
public:
	bool isNumber(string s) {
		enum inputType{
			invalid,space,sign,digit,dot,e
		};
		const int state[][9] = {
			{-1,  0,  3,  1,  2, -1},	//space
			{-1,  8, -1,  1,  4,  5},	//digit
			{-1, -1, -1,  4, -1, -1},	//dot
			{-1, -1, -1,  1,  2, -1},	//+-
			{-1,  8, -1,  4, -1,  5},	//有了dot
			{-1, -1,  6,  7, -1, -1},	//e
			{-1, -1, -1,  7, -1, -1},	//有了e
			{-1,  8, -1,  7, -1, -1},	//e后有了数字
			{-1,  8, -1, -1, -1, -1}	//最后的space
		};
		int st = 0;
		for (auto str : s){
			inputType T = invalid;
			if (isspace(str))
				T = space;
			else if (isdigit(str))
				T = digit;
			else if (str == '+' || str == '-')
				T = sign;
			else if (str == '.')
				T = dot;
			else if (str == 'e' || str == 'E')
				T = e;
			st = state[st][T];
			if (st == -1) return false;
		}
		return st == 1 || st == 4 || st == 7 || st == 8;
	}
};

//void main(){
//	Solution s;
//	s.isNumber("3.");
//}