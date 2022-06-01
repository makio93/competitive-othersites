// 本番

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class AddFlowers {
public:
    vector<string> add(vector<string> lawn) {
        int m = lawn.size(), n = lawn.front().size();
        vector<string> res(m, string(n, '.'));
        rep(i, m) rep(j, n) if (lawn[i][j] == 'F') {
            int ui = i, li = j, di = ui + 1, ri = li + 1;
            if (di >= m) { --ui; --di; }
            if (ri >= n) { --li; --ri; }
            rep3(i2, ui, di+1) rep3(j2, li, ri+1) res[i2][j2] = 'F';
        }
        return res;
    }
};
