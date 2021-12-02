#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xsum = 0;
        for (int i=0; i<n; ++i) xsum ^= nums[i];
        vector<int> ans(n);
        for (int i=n-1; i>=0; --i) {
            ans[n-i-1] = ((1<<maximumBit)-1) - xsum;
            xsum ^= nums[i];
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
