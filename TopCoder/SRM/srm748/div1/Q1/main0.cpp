// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
const ll mod = (ll)(1e9) + 7;

class EraseToGCD {
public:
    int countWays(vector<int> S, int goal) {
        int n = S.size();
        unordered_map<int, ll> wcnt;
        rep(i, n) {
            unordered_map<int, ll> add;
            if (!wcnt.empty()) {
                for (auto pi : wcnt) {
                    int gval = gcd(S[i], pi.first);
                    add[gval] = (add[gval] + pi.second) % mod;
                }
            }
            add[S[i]]++;
            for (auto pi : add) wcnt[pi.first] = (wcnt[pi.first] + pi.second) % mod;
        }
        return wcnt[goal];
    }
};
