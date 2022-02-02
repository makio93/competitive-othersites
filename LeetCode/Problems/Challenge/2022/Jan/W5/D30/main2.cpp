#include <bits/stdc++.h>
using namespace std;

// 解説AC,解法2

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return;
        int cnt = 0, sid = 0;
        while (cnt < n) {
            int id = sid, fr = nums[sid], to = -1;
            do {
                to = nums[(id+k)%n];
                nums[(id+k)%n] = fr;
                swap(to, fr);
                id = (id + k) % n;
                ++cnt;
            } while (id != sid);
            ++sid;
        }
    }
};
