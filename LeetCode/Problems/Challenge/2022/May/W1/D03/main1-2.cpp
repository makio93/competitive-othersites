// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> lst, rst;
        int li = n, ri = -1;
        for (int i=0; i<n; ++i) {
            while (!lst.empty() && nums[lst.top()]>nums[i]) {
                li = min(li, lst.top());
                lst.pop();
            }
            lst.push(i);
        }
        for (int i=n-1; i>=0; --i) {
            while (!rst.empty() && nums[rst.top()]<nums[i]) {
                ri = max(ri, rst.top());
                rst.pop();
            }
            rst.push(i);
        }
        if (li == n) return 0;
        return ri - li + 1;
    }
};
