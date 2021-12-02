// 解説を一部見てから実装、その２

#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long mod = (1<<31);
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(target+1);
        dp[0] = 1;
        for (int i=1; i<=target; ++i) {
            for (int j=0; j<n; ++j) if (i-nums[j] >= 0) dp[i] = (dp[i] + dp[i-nums[j]]) % mod;
        }
        return (int)dp[target];
    }
};

int main(){
    Solution cl;
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cin >> target;
    cout << cl.combinationSum4(nums, target) << endl;
    return 0;
}
