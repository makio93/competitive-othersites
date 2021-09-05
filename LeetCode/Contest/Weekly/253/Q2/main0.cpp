#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> que;
        for (int i=0; i<n; ++i) que.push(piles[i]);
        for (int i=0; i<k; ++i) {
            int pi = que.top(); que.pop();
            que.push((pi+1)/2);
        }
        int res = 0;
        while (!que.empty()) { res += que.top(); que.pop(); }
        return res;
    }
};
