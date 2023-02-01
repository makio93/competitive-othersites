// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (int i=0; i<3; ++i) if (amount[i] > 0) pq.push(amount[i]);
        int res = 0;
        while (!pq.empty()) {
            int val1 = pq.top(); pq.pop();
            if (pq.empty()) res += val1;
            else {
                int val2 = pq.top(); pq.pop();
                ++res, --val1, --val2;
                if (val1 > 0) pq.push(val1);
                if (val2 > 0) pq.push(val2);
            }
        }
        return res;
    }
};
