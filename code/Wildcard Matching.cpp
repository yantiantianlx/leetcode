#include "Header.h"

class Solution {
public:
	bool isMatch(string s, string p) {
		return ismatch(s.c_str(), p.c_str());
	}

private:
	bool ismatch(const char *s, const char *p){
		const char* str = s, *ptr = p;
		bool is_star = false;
		while (*str){
			switch (*ptr)
			{
				case '?' :{
					str++, ptr++; 
				}break; 
				//在出现*时，记录当前的str，ptr
				case '*':{
					is_star = true;
					s = str; p = ptr;
					while (*p == '*') p++;
					ptr = p;
				}break;
				default:{
					if (*str != *ptr){
						if (is_star){
							s++; str = s;
							ptr = p;
						}else return false;
					}else{
						ptr++;
						str++;
					}
				}break;
			}
		}
		while (*ptr == '*') ptr++;
		if (*ptr == '\0') return true;
		else return false;
	}
};

//void main(){
//	Solution s;
//	s.isMatch("aa","*");
//}