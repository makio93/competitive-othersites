// 初見,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class MultiplicationTable2 {
public:
    int minimalGoodSet(vector<int> table) {
        int n2 = table.size();
        int n = 1;
        while (n*n < n2) ++n;
        int res = n;
        rep(i, n) {
            set<int> s;
            s.insert(i);
            while (1) {
                set<int> ns = s;
                for (int v1 : s) for (int v2 : s) ns.insert(table[v1*n+v2]);
                if (ns == s) break;
                swap(ns, s);
            }
            res = min(res, (int)(s.size()));
        }
        return res;
    }
};
