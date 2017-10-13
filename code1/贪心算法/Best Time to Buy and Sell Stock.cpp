#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int min_price = prices[0];
		int min_dif = 0;
		for (int i = 1; i < prices.size(); i++) {
			min_dif = max(min_dif, prices[i] - min_price);
			min_price = min(min_price, prices[i]);

		}
		return min_dif;
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int sum = 0;
		for (int i = 0; i < prices.size() - 1; i++)
			if (prices[i + 1] > prices[i])
				sum += prices[i + 1] - prices[i];
		return sum;
	}
};

//int main() {
//	vector<int> a = { 7, 1, 5, 3, 6, 4 };
//	Solution s;
//	cout<<s.maxProfit(a);
//	cin.get();
//	return 0;
//}