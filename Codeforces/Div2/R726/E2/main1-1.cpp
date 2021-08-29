#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC(自力の実装)

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int mid = 0;
    rep3(i, 1, n) {
        int tid = i - (mid + 1);
        if (s[tid] < s[i]) break;
        else if (s[tid] > s[i]) mid = i;
        else if (i-mid == mid+1) mid = i;
    }
    string res;
    while ((int)(res.length()) < k) res += s.substr(0, mid+1);
    res = res.substr(0, k);
    cout << res << endl;
    return 0;
}
