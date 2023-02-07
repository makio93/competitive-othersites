// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), mval = (int)(2e9), res = (int)(2e9);
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) {
            int val = nums[i];
            if (val%2 == 1) val *= 2;
            mval = min(mval, val);
            pq.push(val);
        }
        while (pq.top()%2 == 0) {
            int tval = pq.top(); pq.pop();
            res = min(res, tval-mval);
            tval /= 2;
            mval = min(mval, tval);
            pq.push(tval);
        }
        return min(res, pq.top()-mval);
    }
};
