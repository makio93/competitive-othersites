// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class SnookerScoring {
public:
    vector<int> scoreN(int N, int R, int C) {
        vector<int> res;
        if (N <= 2) res.push_back(N);
        else if (N == 5) for (int vi : { 1, 3, 1 }) res.push_back(vi);
        else {
            vector<int> suffix;
            rep3(i, 2, C+2) {
                if (N <= R*(C+2)) break;
                suffix.push_back(i);
                N -= i;
            }
            int sum = 0;
            while (sum < N) {
                for (int vi : { 1, C+1 }) {
                    res.push_back(vi);
                    sum += vi;
                }
            }
            int m = res.size();
            rep(i, m/2) {
                if (sum == N) break;
                while (res[i*2+1]>2 && sum>N) {
                    res[i*2+1]--;
                    sum--;
                }
            }
            if (!suffix.empty()) for (int vi : suffix) res.push_back(vi);
        }
        return res;
    }
};
