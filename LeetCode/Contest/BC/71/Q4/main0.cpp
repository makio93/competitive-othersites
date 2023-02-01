#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> lsum(2*n+1), rsum(2*n+1);
        long long sum = 0;
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            pq.push(nums[i]);
        }
        lsum[0] = sum;
        for (int i=0; i<2*n; ++i) {
            sum += nums[n+i];
            pq.push(nums[n+i]);
            sum -= pq.top(); pq.pop();
            lsum[i+1] = sum;
        }
        sum = 0;
        priority_queue<int, vector<int>, greater<int>> lpq;
        for (int i=0; i<n; ++i) {
            sum += nums[n3-i-1];
            lpq.push(nums[n3-i-1]);
        }
        rsum[2*n] = sum;
        for (int i=0; i<2*n; ++i) {
            sum += nums[2*n-i-1];
            lpq.push(nums[2*n-i-1]);
            sum -= lpq.top(); lpq.pop();
            rsum[2*n-i-1] = sum;
        }
        long long res = (long long)(1e15);
        for (int i=0; i<=n; ++i) res = min(res, lsum[i]-rsum[n+i]);
        return res;
    }
};
