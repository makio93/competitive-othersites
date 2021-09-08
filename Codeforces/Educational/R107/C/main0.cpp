#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), t(q);
    rep(i, n) cin >> a[i];
    rep(i, q) cin >> t[i];
    map<int, int> cpos;
    repr(i, n) cpos[a[i]] = i+1;
    vector<int> ans(q);
    rep(i, q) {
        int pos = cpos[t[i]];
        ans[i] = pos;
        for (auto itr=cpos.begin(); itr!=cpos.end(); ++itr) if (itr->second < pos) itr->second++;
        cpos[t[i]] = 1;
    }
    rep(i, q) printf("%d%c", ans[i], (i<q-1?' ':'\n'));
    return 0;
}
