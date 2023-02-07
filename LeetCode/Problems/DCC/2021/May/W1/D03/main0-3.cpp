#include <bits/stdc++.h>
using namespace std;

// 自力AC,Space削減2

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        auto itr = nums.begin();
        while (itr+1 != nums.end()) {
            *(itr+1) += *itr;
            ++itr;
        }
        return nums;
    }
};
