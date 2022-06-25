// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        ll sum = 0;
        for (int i=0; i<n; ++i) sum += target[i];
        priority_queue<int> pq(target.begin(), target.end());
        while (sum > (ll)(pq.size())) {
            int vi = pq.top(); pq.pop();
            sum -= vi;
            if (vi<sum || sum==0 || (sum>1&&vi%sum==0)) return false;
            if (sum == 1) vi = sum;
            else vi %= sum;
            sum += vi;
            pq.push(vi);
        }
        return true;
    }
};
