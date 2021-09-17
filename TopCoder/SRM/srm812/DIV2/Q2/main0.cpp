// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class MarsHabitats {
public:
    vector<int> design(vector<int> distances) {
        int n = distances.size();
        if (n%2 == 1) return vector<int>();
        vector<int> res(6*n);
        vector<pair<int, int>> sdis(n);
        rep(i, n) sdis[i] = { distances[i], i };
        sort(all(sdis));
        int sum = 0;
        rep(i, n-1) {
            int sub = sdis[i+1].first - sdis[i].first;
            res[6*(sdis[i].second)+0] = sdis[i+1].second + 1;
            res[6*(sdis[i+1].second)+2] = sdis[i].second + 1;
            res[6*(sdis[i].second)+1] = res[6*(sdis[i+1].second)+3] = sub;
            if (i%2 == 0) {
                res[6*(sdis[i].second)+4] = sdis[i+1].second + 1;
                res[6*(sdis[i+1].second)+4] = sdis[i].second + 1;
                res[6*(sdis[i].second)+5] = res[6*(sdis[i+1].second)+5] = sub;
            }
            sum += sub;
        }
        res[6*(sdis[0].second)+4] = sdis[n-1].second + 1;
        res[6*(sdis[n-1].second)+4] = sdis[0].second + 1;
        res[6*(sdis[0].second)+5] = res[6*(sdis[n-1].second)+5] = sum;
        return res;
    }
};
