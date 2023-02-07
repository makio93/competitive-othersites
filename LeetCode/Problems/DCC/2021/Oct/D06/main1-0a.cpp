#include <bits/stdc++.h>
using namespace std;

// 解説AC,O(n^2)解法,TLE

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) if (nums[j] == nums[i]) {
                res.push_back(nums[i]);
                break;
            }
        }
        return res;
    }
};
