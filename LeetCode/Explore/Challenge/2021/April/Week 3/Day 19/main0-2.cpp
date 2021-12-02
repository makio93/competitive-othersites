// 解説を一部見てから実装

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct mint {
        long long mod = (1e9) + 7;
        long long x;
        mint(long long x=0):x((x%mod+mod)%mod){}
        mint operator-() const { return mint(-x);}
        mint& operator+=(const mint a) {
            if ((x += a.x) >= mod) x -= mod;
            return *this;
        }
        mint& operator-=(const mint a) {
            if ((x += mod-a.x) >= mod) x -= mod;
            return *this;
        }
        mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
        mint operator+(const mint a) const { return mint(*this) += a;}
        mint operator-(const mint a) const { return mint(*this) -= a;}
        mint operator*(const mint a) const { return mint(*this) *= a;}
        mint pow(long long t) const {
            if (!t) return 1;
            mint a = pow(t>>1);
            a *= a;
            if (t&1) a *= *this;
            return a;
        }
        mint inv() const { return pow(mod-2);}
        mint& operator/=(const mint a) { return *this *= a.inv();}
        mint operator/(const mint a) const { return mint(*this) /= a;}
    };
    struct combination {
        vector<mint> fact, ifact;
        combination(int n):fact(n+1),ifact(n+1) {
            fact[0] = 1;
            for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
            ifact[n] = fact[n].inv();
            for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
        }
        mint operator()(int n, int k) {
            if (k < 0 || k > n) return 0;
            return fact[n]*ifact[k]*ifact[n-k];
        }
    };
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<map<int, mint>>> dp(n+1, vector<map<int, mint>>(target+1));
        combination cb(target);
        dp[0][0][0] = 1;
        for (int i=0; i<n; ++i) for (int j=0; j<=target; ++j) if (!dp[i][j].empty()) {
            int mval = dp[i][j].rbegin()->first;
            for (int k=0; k<=mval; ++k) {
                if (dp[i][j].find(k) != dp[i][j].end()) {
                    for (int d=0; j+d*nums[i]<=target; ++d) dp[i+1][j+d*nums[i]][k+d] += dp[i][j][k] * cb(k+d, d);
                }
            }
        }
        long long res = 0;
        for (auto itr=dp[n][target].begin(); itr!=dp[n][target].end(); ++itr) res += itr->second.x;
        return (int)res;
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
