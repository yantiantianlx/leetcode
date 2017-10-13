#include "Header.h"
#include <algorithm>

class Solution {
public:
	int candy(vector<int>& ratings) {
		//将波谷设为1
		vector<int> f(ratings.size());
		int sum = 0;
		for (int i = 0; i < ratings.size(); ++i)
			sum += candy(ratings, f, i);
		return sum;
	}

private:
	//传参要加引用，否则传值，参数数据过多，存储空间不足
	int candy(vector<int>& ratings, vector<int>& f, int i){
		if (f[i] == 0) {
			f[i] = 1;
			if (i > 0 && ratings[i] > ratings[i - 1])
				f[i] = max(f[i], candy(ratings, f, i - 1) + 1);
			if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1])
				f[i] = max(f[i], candy(ratings, f, i + 1) + 1);
		}
		return f[i];
	}
};