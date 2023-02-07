#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        bool rev = (k > n/2);
        if (rev) k = n-k;
        if (!rev) reverse(nums.begin(), nums.end());
        for (int i=0; i<k; ++i) nums.push_back(nums[i]);
        reverse(nums.begin(), nums.end());
        for (int i=0; i<k; ++i) nums.pop_back();
        if (rev) reverse(nums.begin(), nums.end());
    }
};
