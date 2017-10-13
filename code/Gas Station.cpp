#include "Header.h"

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (!gas.size()) return -1;
		int total = 0;
		int sum = 0;
		int pos = -1;
		for (int i = 0; i < gas.size(); i++){
			total += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			if (sum < 0){
				sum = 0;
				pos = i;
			}
		}
		return total >= 0 ? pos + 1 : -1;
	}
};