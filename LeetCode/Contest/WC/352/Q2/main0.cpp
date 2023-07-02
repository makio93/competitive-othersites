// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        for (int i=2; i*i<=n; ++i) if (primes[i]) for (int j=i*2; j<=n; j+=i) primes[j] = false;
        vector<vector<int>> res;
        for (int x=2; x<=n/2; ++x) {
            int y = n - x;
            if (y < x || !primes[x] || !primes[y]) continue;
            res.push_back({ x, y });
        }
        sort(res.begin(), res.end());
        return res;
    }
};
