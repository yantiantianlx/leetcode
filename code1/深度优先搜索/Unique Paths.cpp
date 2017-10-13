#include <iostream>
#include <vector>
using namespace std;

//³¬Ê±
class Solution1 {
public:
	int uniquePaths(int m, int n) {
		return uniquePaths(m, n, 1, 1);
	}
	int uniquePaths(int m, int n, int start_m, int start_n) {
		if (m == start_m  ||  n == start_n)
			return 1;
		else if (start_m < m && start_n < n)
			return uniquePaths(m, n, start_m + 1, start_n) + uniquePaths(m, n, start_m, start_n + 1);
	}
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0;
		if (m == 1 || n == 1) return 1;
		vector<int> f(n, 0);
		f[0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 1; j < n; j++)
				f[j] = f[j] + f[j - 1];
		return f[n - 1];

	}
};

//int main() {
//	Solution s;
//	cout << s.uniquePaths(7,3);
//	cin.get();
//	return 0;
//}