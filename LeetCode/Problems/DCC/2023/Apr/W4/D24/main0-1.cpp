// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if (n == 1) return stones[0];
        partial_sort(stones.begin(), stones.begin()+2, stones.end(), greater<int>());
        while (stones[1] > 0) {
            stones[0] -= stones[1];
            stones[1] = 0;
            partial_sort(stones.begin(), stones.begin()+2, stones.end(), greater<int>());
        }
        return stones[0];
    }
};
