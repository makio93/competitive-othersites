#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (i != j) {
            if (nums[i]+nums[j] == target) ++res;
        }
        return res;
    }
};
