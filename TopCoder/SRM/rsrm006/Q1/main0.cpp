// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class BiggestDuplicate {
public:
    int findLargest(vector<int> x) {
        int n = x.size();
        unordered_map<int, int> cnt;
        rep(i, n) cnt[x[i]]++;
        int res = -1;
        for (auto pi : cnt) if (pi.second > 1) res = max(res, pi.first);
        return res;
    }
};
