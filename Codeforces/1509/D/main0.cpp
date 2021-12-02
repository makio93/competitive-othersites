#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        vector<string> b(3);
        rep(i, 3) cin >> b[i];
        vector<int> dcnt(3);
        vector<pair<int, int>> id = { { 0, 1 }, { 0, 2 }, { 1, 2 } };
        rep(i, 3) {
            rep(j, 2*n) if (b[id[i].first][j] == b[id[i].second][j]) ++dcnt[i];
        }
        pair<int, int> mid = { -1, -1 };
        rep(i, 3) mid = max(mid, pair<int,int>{dcnt[i],i});
        string ans;
        pair<int, int> did = id[mid.second];
        vector<vector<vector<int>>> sum(2*n+1, vector<vector<int>>(3, vector<int>(2)));
        rep(i, 2*n) {
            sum[i+1][0][0] = sum[i][0][0] + (b[did.first][i]=='0'?1:0);
            sum[i+1][0][1] = sum[i][0][1] + (b[did.first][i]=='1'?1:0);
            sum[i+1][1][0] = sum[i][1][0] + (b[did.second][i]=='0'?1:0);
            sum[i+1][1][1] = sum[i][1][1] + (b[did.second][i]=='1'?1:0);
            if (b[did.first][i] == b[did.second][i]) {
                ans += b[did.first][i];
                sum[i+1][2][0] = sum[i][2][0] + (ans.back()=='0'?1:0);
                sum[i+1][2][1] = sum[i][2][1] + (ans.back()=='1'?1:0);
            }
            else {
                string add;
                sum[i+1][2][0] = sum[i][2][0];
                sum[i+1][2][1] = sum[i][2][1];
                if (sum[i+1][2][0]<sum[i+1][0][0]||sum[i+1][2][0]<sum[i+1][1][0]) {
                    add += '0';
                    sum[i+1][2][0]++;
                }
                if (sum[i+1][2][1]<sum[i+1][0][1]||sum[i+1][2][1]<sum[i+1][1][1]) {
                    add += '1';
                    sum[i+1][2][1]++;
                }
                if (i+1<2*n) {
                    if (b[did.first][i+1]==b[did.second][i+1]) {
                        if (b[did.first][i+1]!=add.back()) reverse(all(add));
                    }
                }
                ans += add;
            }
        }
        cout << ans.substr(0, 3*n) << endl;
    }
    return 0;
}
