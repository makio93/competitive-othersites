// 解説1-1t:解答データ生成用ソースコード

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
static vector<vector<int>> ans;
class UpdownNumbers {
public:
    int count(int D, int S) {
        if (ans.empty()) {
            const int MD = 100, MS = 10;
            ans = vector<vector<int>>(MD+1, vector<int>(MS+1));
            vector<vector<ll>> dp(1<<10, vector<ll>(1<<10));
            rep3(i, 1, 10) {
                dp[1<<i][1<<(9-i)] += 1;
                ans[1][1] += 1;
            }
            rep3(i, 1, MD) {
                vector<vector<ll>> ndp(1<<10, vector<ll>(1<<10));
                rep(i1, 1<<10) rep(j1, 1<<10) rep(i2, 10) {
                    int lid = ((i1>>i2)&(-(i1>>i2)))<<i2, rid = ((j1>>(9-i2))&(-(j1>>(9-i2))))<<(9-i2);
                    int b1 = (i1^lid)|(1<<i2), b2 = (j1^rid)|(1<<(9-i2));
                    ndp[b1][b2] = (ndp[b1][b2] + dp[i1][j1]) % mod;
                }
                swap(ndp, dp);
                rep(i1, 1<<10) rep(j1, 1<<10) rep3(s, 1, 11) 
                    if (__builtin_popcount(i1)>=s && __builtin_popcount(j1)>=s) ans[i+1][s] = (ans[i+1][s] + dp[i1][j1]) % mod;
            }
        }
        return (int)ans[D][S];
    }
};

int main() {
    UpdownNumbers cl;
    cl.count(1, 1);
    cout << "{" << endl;
    rep3(i, 1, 100+1) {
        cout << "{ ";
        rep3(j, 1, 10+1) {
            cout << ans[i][j];
            if (j < 10) cout << ",";
            cout << " ";
        }
        cout << " }";
        if (i < 100) cout << ",";
        cout << endl;
    }
    cout << "}" << endl;
    return 0;
}
