#include "Header.h"
#include <array>
class Solution {
public:
	int myAtoi(string str) {
		int result = 0;
		int signal = 0;//0为正数
		char* s = (char*)str.c_str();
		//越过前面的空格
		while (*s == ' ') s++;

		while (s){
			if (*s == '-'){ 
				signal = 1; 
				s++; 	
			}
			else if (*s == '+') 
				s++;
			//遇到数字以外的就跳出，包括空格
			if (*s < '0' || *s > '9')
				break;
			if (result > INT_MAX / 10 ||
				(result == INT_MAX / 10 && *s > '7'))
				return  signal ? INT_MIN : INT_MAX;
			result = result * 10 + *s - '0';
			s++;
		}
		return signal ? (0 - result) : result;
	}
};

//void main(){
//	Solution s;
//	s.myAtoi("+1")
//	system("pause");
//}