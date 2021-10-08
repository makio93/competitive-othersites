// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class DevuAndRabbitNumbering {
    vector<string> tar = { "can", "cannot" };
public:
    string canRenumber(vector<int> rabbitIds) {
        int n = rabbitIds.size();
        sort(all(rabbitIds));
        set<int> vals;
        rep(i, n) {
            if (vals.find(rabbitIds[i]-1) == vals.end()) {
                rabbitIds[i]--;
                vals.insert(rabbitIds[i]);
            }
            else if (vals.find(rabbitIds[i]) == vals.end()) vals.insert(rabbitIds[i]);
            else if (vals.find(rabbitIds[i]+1) == vals.end()) {
                rabbitIds[i]++;
                vals.insert(rabbitIds[i]);
            }
            else return tar[1];
        }
        return tar[0];
    }
};
