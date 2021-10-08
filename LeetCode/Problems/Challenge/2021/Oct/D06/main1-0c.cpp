#include <bits/stdc++.h>
using namespace std;

// 解説AC,Time:O(n),Space:O(n)解法

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        vector<int> res;
        for (int i=0; i<n; ++i) {
            vcnt[nums[i]]++;
            if (vcnt[nums[i]] == 2) res.push_back(nums[i]);
        }
        return res;
    }
};
