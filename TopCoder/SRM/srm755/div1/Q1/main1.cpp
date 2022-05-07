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
        rep(i, n) {
            if (target[i] == i) continue;
            int tid = find(all(target), i) - target.begin();
            res.push_back(i);
            res.push_back(tid);
            res.push_back(n);
            swap(target[i], target[tid]);
        }
        return res;
    }
};
