// 復習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class SnookerScoring {
    vector<int> make_red(int N, int C) {
        vector<int> ret;
        int len = (N+C+1) / (C+2), sum = len * (C+2);
        rep(i, len) ret.insert(ret.end(), { 1, C+1 });
        while (sum > N) {
            rep(i, len) if (ret[i*2+1] > 2) {
                ret[i*2+1]--;
                --sum;
                break;
            }
        }
        return ret;
    }
public:
    vector<int> scoreN(int N, int R, int C) {
        if (N <= 2) return vector<int>({ N });
        if (N == 5) return vector<int>({ 1, 3, 1 });
        vector<int> suf;
        if (N > R*(C+2)) {
            rep3(i, 2, C+2) {
                suf.push_back(i);
                N -= i;
            }
        }
        vector<int> res = make_red(N, C);
        res.insert(res.end(), all(suf));
        return res;
    }
};
