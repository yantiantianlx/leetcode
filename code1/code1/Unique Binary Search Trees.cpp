#include <algorithm>
#include <vector>
using namespace std;
//运行时间长 6ms， 递归
class Solution {
public:
	int numTrees(int n) {
		if ( n <= 1) return 1;
		int sum = 0;
		for (int i = 0; i <= (n-1)/2; i++) {
			if( i == (n - i - 1) )
				sum += pow(numTrees(i),2);
			else
				sum += numTrees(i) * numTrees(n - i -1) * 2;
		}
		return sum;
	}
};

class Solution1 {
public:
	int numTrees(int n) {
		if (n <= 1) return 1;
		vector<int> f(n+1, 0);
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				f[i] += f[j - 1] * f[i - j];
			}
		}
		return f[n];
	}
};


