// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        ll sum = accumulate(target.begin(), target.end(), 0LL);
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) pq.push(target[i]);
        while (pq.top() > 1) {
            int tval = pq.top(); pq.pop();
            sum -= tval;
            if (sum<=0 || sum>=tval || (sum>1&&tval%sum==0)) return false;
            if (sum == 1) return true;
            tval %= sum;
            sum += tval;
            pq.push(tval);
        }
        return true;
    }
};
