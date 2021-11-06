// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class DogsInAGrid {
    string tar = "DG";
public:
    vector<string> construct(int N) {
        vector<string> res(40, string(40, 'O'));
        int cnt = 0;
        if (N > 19) {
            for (int i=0; i<40; ++i) res[0][i] = 'D';
            for (int i=2; i<39; i+=2) {
                for (int j=0; j<40; ++j) {
                    res[i][j] = tar[i%4/2];
                    if (j<2 || 39-j<2) cnt += 2;
                    else cnt += 3;
                    if (N-cnt <= 19) break;
                }
                if (N-cnt <= 19) break;
            }
        }
        if (N-cnt > 0) {
            res[39][0] = 'D';
            for (int i=2; i<40; i+=2) {
                res[39][i] = tar[i%4/2];
                ++cnt;
                if (cnt == N) break;
            }
        }
        return res;
    }
};
