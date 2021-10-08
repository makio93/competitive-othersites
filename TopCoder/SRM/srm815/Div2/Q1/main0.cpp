// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class SunShroom {
public:
    long long produceSun(vector<long long> plantingTime, long long queryTime) {
        int n = plantingTime.size();
        ll res = 0;
        rep(i, n) {
            if (plantingTime[i] <= queryTime) {
                if (plantingTime[i]+120 <= queryTime) {
                    res += 15 * 4;
                    res += 25LL * ((queryTime-(plantingTime[i]+120)) / 24 + 1);
                }
                else {
                    res += 15LL * ((queryTime - plantingTime[i]) / 24);
                }
            }
        }
        return res;
    }
};
