#include <bits/stdc++.h>
using namespace std;

// 解説AC,解法5

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return;
        int sid = 0;
        while (k > 0) {
            if (k > n-k) {
                int tmpk = n - k;
                for (int i=0; i<tmpk; ++i) swap(nums[sid+i], nums[sid+tmpk+i]);
                sid += tmpk;
                n -= tmpk;
                k -= tmpk;
            }
            else {
                for (int i=0; i<k; ++i) swap(nums[sid+n-2*k+i], nums[sid+n-k+i]);
                n -= k;
                k %= n;
            }
        }
    }
};
