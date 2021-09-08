#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> sum(n+1, vector<int>(2));
        rep(i, n) {
            rep(j, 2) sum[i+1][j] += sum[i][j];
            if (s[i] == 'a') sum[i+1][0]++;
            else sum[i+1][1]++;
        }
        int l = -1, r = -1;
        rep3(i, 1, n+1) {
            rep3r(j, 0, i) if (sum[i][0]-sum[j][0] == sum[i][1]-sum[j][1]) {
                l = j + 1; r = i;
                break;
            }
            if (l!=-1 || r!=-1) break;
        }
        cout << l << ' ' << r << endl;
    }
    return 0;
}
