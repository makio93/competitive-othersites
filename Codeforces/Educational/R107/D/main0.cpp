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
    int n, k;
    cin >> n >> k;
    string roop;
    rep(i, k) {
        roop += (char)('a'+i);
        for (int j=i+1; j<k; ++j) roop += (string){ (char)('a'+i), (char)('a'+j) };
    }
    string ans;
    int rcnt = n / (int)(roop.size()), mcnt = n % (int)(roop.size());
    rep(i, rcnt) ans += roop;
    ans += roop.substr(0, mcnt);
    cout << ans << endl;
    return 0;
}
