#include "Header.h"

class Solution {
public:
	bool isMatch(string s, string p) {
		return ismatch(s.c_str(), p.c_str());
	}

private:
	bool ismatch(const char* str, const char* ptr){
		if (*ptr == '\0') return *str == '\0';
		if (*(ptr+1) != '*'){
			if ((*ptr == '.' && *str != '\0') || (*ptr != '.' && *str == *ptr))
				return ismatch(str + 1, ptr + 1);
			else
				return false;
		}
		else{
			while ((*ptr == '.' && *str != '\0') || (*ptr != '.' && *str == *ptr)){
				if (ismatch(str, ptr + 2))
					return true;
				str++;
			}	
			return ismatch(str, ptr + 2);
		}
	}
};

