// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, id = 0;
        sort(nums.begin(), nums.end());
        while (id < n) {
            id = upper_bound(nums.begin(), nums.end(), nums[id]+k) - nums.begin();
            ++res;
        }
        return res;
    }
};
