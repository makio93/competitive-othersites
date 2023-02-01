// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size(), m = operations.size();
        vector<int> vids((int)(1e6)+1, -1);
        for (int i=0; i<n; ++i) vids[nums[i]] = i;
        for (int i=0; i<m; ++i) {
            nums[vids[operations[i][0]]] = operations[i][1];
            vids[operations[i][1]] = vids[operations[i][0]];
            vids[operations[i][0]] = -1;
        }
        return nums;
    }
};
