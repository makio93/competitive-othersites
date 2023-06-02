// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza.front().length();
        vector dp(k+1, vector(rows+1, vector(cols+1, 0LL)));
        vector apples(rows+1, vector(cols+1, 0));
        for (int i=rows-1; i>=0; --i) for (int j=cols-1; j>=0; --j) apples[i][j] = (pizza[i][j] == 'A' ? 1 : 0) + apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
        for (int ki=0; ki<=k; ++ki) for (int ri=rows; ri>=0; --ri) for (int ci=cols; ci>=0; --ci) {
            if (ki == 0) dp[ki][ri][ci] = (ri == rows || ci == cols) ? 1 : 0;
            else if (ki == 1) dp[ki][ri][ci] = (apples[ri][ci] > 0) ? 1 : 0;
            else {
                for (int nri=ri+1; nri<rows; ++nri) if (apples[ri][ci] - apples[nri][ci] > 0) dp[ki][ri][ci] = (dp[ki][ri][ci] + dp[ki-1][nri][ci]) % mod;
                for (int nci=ci+1; nci<cols; ++nci) if (apples[ri][ci] - apples[ri][nci] > 0) dp[ki][ri][ci] = (dp[ki][ri][ci] + dp[ki-1][ri][nci]) % mod;
            }
        }
        return (int)dp[k][0][0];

    }
};
