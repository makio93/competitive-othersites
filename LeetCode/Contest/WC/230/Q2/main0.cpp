// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size(), m = toppingCosts.size();
        pair<int, int> ans = { (int)(1e9), (int)(1e9) };
        int three = 1;
        for (int i=0; i<m; ++i) three *= 3;
        for (int i1=0; i1<n; ++i1) {
            for (int i=0; i<three; ++i) {
                int tval = 0, ti = i;
                for (int j=0; j<m; ++j) {
                    tval += toppingCosts[j] * (ti%3);
                    ti /= 3;
                }
                ans = min(ans, (pair<int,int>){abs(target-(baseCosts[i1]+tval)),baseCosts[i1]+tval});
            }
        }
        return ans.second;
    }
};
