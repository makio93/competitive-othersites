// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class OneHandSort {
public:
    vector<int> sortShelf(vector<int> target) {
        int n = target.size();
        vector<int> res;
        vector<int> rtar(n);
        rep(i, n) rtar[target[i]] = i;
        rep(i, n) {
            if (target[i] == i) continue;
            res.push_back(rtar[i]);
            res.push_back(i);
            res.push_back(n);
            int tid = rtar[i], uval = target[i];
            target[i] = i;
            rtar[i] = i;
            target[tid] = uval;
            rtar[uval] = tid;
        }
        return res;
    }
};
