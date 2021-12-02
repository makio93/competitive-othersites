#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    long long comb(int a, int b) {
        if (a < b) return 0;
        if (a-b < b) return comb(a, a-b);
        long long res = 1;
        for (int i=0; i<b; ++i) res = res * (a-i) / (1+i);
        return res;
    }
    long long dfs(vector<int>& nums, vector<int>& perm, int tar, int d=0) {
        if (d == n-1) {
            if (tar%nums[d] != 0) return 0;
            else {
                long long res = 1;
                int cnt = tar / nums[d];
                for (int i=0; i<n-1; ++i) cnt += perm[i];
                for (int i=0; i<n-1; ++i) {
                    res *= comb(cnt, perm[i]);
                    cnt -= perm[i];
                }
                return res;
            }
        }
        else {
            int sub = tar / nums[d];
            long long res = 0;
            for (int i=0; i<=sub; ++i) {
                perm[d] = i;
                res += dfs(nums, perm, tar-nums[d]*i, d+1);
            }
            return res;
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> perm(n-1);
        return (int)dfs(nums, perm, target);
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
