// 復習1回目,自力AC

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
        int n = table.size();
        int m = 1;
        while (m*m < n) ++m;
        int res = m;
        rep(i, m) {
            unordered_set<int> st;
            st.insert(i);
            while ((int)(st.size()) < res) {
                unordered_set<int> add;
                for (int v1 : st) for (int v2 : st) 
                    if (st.find(table[v1*m+v2]) == st.end()) add.insert(table[v1*m+v2]);
                if (add.empty()) break;
                for (int val : add) st.insert(val);
            }
            res = min(res, (int)(st.size()));
        }
        return res;
    }
};
