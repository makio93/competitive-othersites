#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), id = -1;
        bool ok = true;
        for (int i=0; i<n-1; ++i) if (nums[i+1] < nums[i]) {
            id = i;
            ok = false;
            break;
        }
        if (ok) return true;
        int tmp = nums[id];
        nums[id] = nums[id+1];
        ok = true;
        for (int i=0; i<n-1; ++i) if (nums[i+1] < nums[i]) {
            ok = false;
            break;
        }
        if (ok) return true;
        nums[id] = tmp;
        nums[id+1] = nums[id];
        for (int i=0; i<n-1; ++i) if (nums[i+1] < nums[i]) return false;
        return true;
    }
};
