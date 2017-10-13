#include <iostream>
#include <vector>
using namespace std;

template<typename iterator>
void merge(iterator start, iterator mid, iterator end) {
	int i1 = mid-start - 1, i2 = end-mid - 1, i3 = i1+i2+1;

	while (i1 >= 0 && i2 >= 0) {
		num1[i3--] = num1[i1] >= num2[m + i2] ? num1[i1--] : num2[m + i2--];
	}
	while (i2 >= 0)
		num1[i3--] = num2[i2--];
}

template<typename iterator>
void merge_sort(iterator start, iterator end) {
	if (start >= end - 1) return;
	int mid = start + (end-start) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, mid, end);
}

void main() {
	vector<int> num = { 3,6,1,4 };
	merge_sort(num.begin(), num.end());
	int a = 0;
}