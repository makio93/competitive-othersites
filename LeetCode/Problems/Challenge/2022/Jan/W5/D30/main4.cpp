#include <bits/stdc++.h>
using namespace std;

// 解説AC,解法4

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), sid = 0;
        k %= n;
        while (k > 0) {
            for (int i=0; i<k; ++i) swap(nums[sid+i], nums[sid+n-k+i]);
            sid += k;
            n -= k;
            k %= n;
        }
    }
};
