// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do res.push_back(nums); while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
