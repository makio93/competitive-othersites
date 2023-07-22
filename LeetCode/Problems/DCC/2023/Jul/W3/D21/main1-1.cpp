// 解説AC

#include <bits/stdc++.h>
using namespace std;

const int MX = numeric_limits<int>::max();
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lens(n, 1), cnts(n, 1);
        for (int i=0; i<n; ++i) for (int j=0; j<i; ++j) if (nums[i] > nums[j]) {
            if (lens[i] < lens[j]+1) {
                lens[i] = lens[j] + 1;
                cnts[i] = cnts[j];
            }
            else if (lens[i] == lens[j] + 1 && cnts[i] <= MX - cnts[j]) cnts[i] += cnts[j];
        }
        int res = 0, tar = *max_element(lens.begin(), lens.end());
        for (int i=0; i<n; ++i) if (lens[i] == tar) res += cnts[i];
        return res;
    }
};
