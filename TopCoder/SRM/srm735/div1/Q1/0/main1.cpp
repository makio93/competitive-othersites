// 

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
        bool ok = true;
        rep(i, n) if (s[i] != s[n-1-i]) ok = false;
        vector<int> res(n, 1);
        if (!ok) {
            rep(i, n) if (s[i] == 'b') res[i] = 2;
            if (res[0] == 2) rep(i, n) res[i] = 3 - res[i];
        }
        return res;
    }
};
