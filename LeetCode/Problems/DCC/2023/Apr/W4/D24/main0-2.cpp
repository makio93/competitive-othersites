// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if (n == 1) return stones[0];
        make_heap(stones.begin(), stones.end());
        auto last = stones.end();
        while (last - stones.begin() > 1) {
            pop_heap(stones.begin(), last--);
            *last -= stones[0];
            pop_heap(stones.begin(), last--);
            swap(*last, *next(last));
            if (*last > 0) push_heap(stones.begin(), ++last);
        }
        return stones[0];
    }
};
