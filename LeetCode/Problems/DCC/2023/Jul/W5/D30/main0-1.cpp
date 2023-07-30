// 自力WA

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        string t;
        t.push_back(s[0]);
        for (int i=1; i<n; ++i) if (t.back() != s[i]) t.push_back(s[i]);
        int m = t.length();
        vector<vector<int>> dp(m, vector<int>(m, INF));
        for (int i=0; i<m; ++i) {
            for (int li=0; li+i<m; ++li) {
                if (i == 0) {
                    dp[li][li] = 1;
                    continue;
                }
                int ri = li + i;
                for (int mi=li+1; mi<=ri; ++mi) dp[li][ri] = min(dp[li][ri], dp[li][mi-1]+dp[mi][ri]);
                for (char ci='a'; ci<='z'; ++ci) if (count(t.begin()+li, t.begin()+ri+1, ci) > 0) {
                    vector<int> mlst;
                    for (int j=li; j<=ri; ++j) if (t[j] == ci) mlst.push_back(j);
                    int val = (li <= mlst.front()-1 ? dp[li][mlst.front()-1] : 0) + 1 + (mlst.back()+1 <= ri ? dp[mlst.back()+1][ri] : 0);
                    for (int j=0; j<(int)(mlst.size())-1; ++j) val += dp[mlst[j]+1][mlst[j+1]-1];
                    dp[li][ri] = min(dp[li][ri], val);
                }
            }
        }
        return dp[0][m-1];
    }
};
