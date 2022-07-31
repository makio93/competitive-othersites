// 復習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class FiringEmployees {
public:
    int fire(vector<int> manager, vector<int> salary, vector<int> productivity) {
        int n = manager.size();
        vector<int> vals(n+1);
        repr(i, n) if (vals[i+1]+productivity[i]-salary[i] > 0) vals[manager[i]] += vals[i+1]+productivity[i]-salary[i];
        return vals[0];
    }
};
