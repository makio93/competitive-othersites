// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size(), m = operations.size();
        unordered_map<int, int> vids;
        for (int i=0; i<n; ++i) vids[nums[i]] = i;
        for (int i=0; i<m; ++i) {
            nums[vids[operations[i][0]]] = operations[i][1];
            vids[operations[i][1]] = vids[operations[i][0]];
        }
        return nums;
    }
};
