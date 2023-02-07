// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int l, int r) -> bool { return l%2 < r%2; });
        return nums;
    }
};
