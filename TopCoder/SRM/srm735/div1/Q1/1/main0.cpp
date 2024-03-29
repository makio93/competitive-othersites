// 復習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class PalindromeSubsequence {
public:
    vector<int> optimalPartition(string s) {
        int n = s.length();
        bool palind = true;
        rep(i, n/2) if (s[i] != s[n-i-1]) {
            palind = false;
            break;
        }
        vector<int> res(n, 1);
        if (!palind) rep(i, n) if (s[i] == 'b') res[i] = 2;
        return res;
    }
};
