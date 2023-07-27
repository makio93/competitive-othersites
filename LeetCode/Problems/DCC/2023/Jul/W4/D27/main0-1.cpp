// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (const int& vi : batteries) pq.push((long long)vi);
        while ((int)(pq.size()) > n) {
            long long lval = pq.top(); pq.pop();
            long long rval = pq.top(); pq.pop();
            pq.push(lval+rval);
        }
        return pq.top();
    }
};
