#include "Header.h"
#include <array>

class Solution {
public:
	string intToRoman(int num) {
		const array<int, 13> radix={1000,900, 500, 400, 100, 90,
			50, 40, 10, 9, 5, 4, 1 };
		const array<string, 13> symbol = {"M","CM","D","CD","C", "XC",
			"L", "XL", "X", "IX", "V", "IV", "I" };

		string result;
		for (int i = 0; i < radix.size(); i++){
			if (num <= 0) return result;
			while (num >= radix[i]){
				num -= radix[i];
				result += symbol[i];
			}
		}
		return result;
	}
};

//void main(){
//	Solution s;
//	s.intToRoman(5467);
//}
