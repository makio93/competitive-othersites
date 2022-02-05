#include <bits/stdc++.h>
using namespace std;

// 解説AC3,貪欲BFS解法,O(N)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), res = 0, pmx = 0, nmx = 0;
        for (int i=0; i<n-1; ++i) {
            nmx = max(nmx, i+nums[i]);
            if (i == pmx) {
                ++res;
                pmx = nmx;
            }
        }
        return res;
    }
};
