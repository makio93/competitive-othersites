// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class StepHopJumpEasy {
public:
    string solve(string level) {
        int n = level.length();
        string res;
        int pos = 0;
        while (pos < n-1) {
            if (pos+1<n && level[pos+1]=='-') {
                res += 'S';
                ++pos;
                continue;
            }
            else if (pos+2<n && level[pos+2]=='-') {
                res += 'H';
                pos += 2;
                continue;
            }
            else if (pos+3<n && level[pos+3]=='-') {
                res += 'J';
                pos += 3;
                continue;
            }
            else return string("");
        }
        return res;
    }
};
