#include <bits/stdc++.h>
using namespace std;

// 解説AC

using ll = long long;
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.length(), m = answers.size();
        int cval = 0;
        for (int i=1,l=0; i<=n; i+=2) {
            if (i==n || s[i]=='+') {
                int mul = 1;
                while (l < i) {
                    mul *= s[l] - '0';
                    l += 2;
                }
                cval += mul;
            }
        }
        vector<vector<unordered_set<int>>> memo(n+1, vector<unordered_set<int>>(n+1));
        function<void(int,int)> calc = [&](int l, int r) {
            if (!memo[l][r].empty() || l%2==1 || (r-l)%2==0 || r-l<=0) return;
            if (r-l == 1) memo[l][r].insert(s[l]-'0');
            else {
                for (int c=l+1; c<r; c+=2) {
                    calc(l, c);
                    calc(c+1, r);
                    for (int lval : memo[l][c]) for (int rval : memo[c+1][r]) {
                        ll tval = (s[c] == '+') ? ((ll)lval + rval) : ((ll)lval * rval);
                        if (tval <= 1000) memo[l][r].insert((int)tval);
                    }
                }
            }
        };
        calc(0, n);
        int res = 0;
        for (int i=0; i<m; ++i) {
            if (answers[i] == cval) res += 5;
            else if (memo[0][n].find(answers[i]) != memo[0][n].end()) res += 2;
        }
        return res;
    }
};
