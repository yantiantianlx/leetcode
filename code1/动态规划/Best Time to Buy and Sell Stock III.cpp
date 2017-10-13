#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1) return 0;
		vector<int> before(n, 0);
		vector<int> after(n, 0);
		int minb = INT_MAX;
		before[0] = 0;
		for (int i = 1; i < n; i++) {
			minb = min(minb, prices[i]);
			before[i] = max(before[i-1], prices[i] - minb);
		}
		int maxa = INT_MIN;
		after[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			maxa = max(maxa, prices[i]);
			after[i] = max(after[i+1], maxa - prices[i]);
		}
		int maxV = 0;
		for (int i = 0; i < n; i++)
			maxV = max(maxV, after[i] + before[i]);
		return maxV;
	}
};

//int main() {
//	vector<int> p = { 2,1,2,0,1 };
//	Solution s;
//	cout<<s.maxProfit(p);
//	cin.get();
//	return 0;
//}