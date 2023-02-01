#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even, odd, res(n);
        for (int i=0; i<n; i+=2) even.push_back(nums[i]);
        for (int i=1; i<n; i+=2) odd.push_back(nums[i]);
        sort(even.begin(), even.end());
        if (!odd.empty()) sort(odd.rbegin(), odd.rend());
        for (int i=0; i<n; i+=2) res[i] = even[i/2];
        for (int i=1; i<n; i+=2) res[i] = odd[i/2];
        return res;
    }
};
