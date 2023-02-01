#include <bits/stdc++.h>
using namespace std;

// 本番AC

const string vowels = "aeiou";
class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        vector<vector<int>> sum(n+1, vector<int>(6));
        for (int i=0; i<n; ++i) {
            bool isv = false;
            for (int j=0; j<5; ++j) {
                if (word[i] == vowels[j]) {
                    sum[i+1][j] = sum[i][j] + 1;
                    isv = true;
                }
                else sum[i+1][j] = sum[i][j];
            }
            if (!isv) sum[i+1][5] = sum[i][5] + 1;
            else sum[i+1][5] = sum[i][5];
        }
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<=n; ++j) {
            int mval = (int)(1e9);
            for (int j2=0; j2<5; ++j2) mval = min(mval, sum[j][j2]-sum[i][j2]);
            if (mval>0 && sum[j][5]-sum[i][5]==0) ++res;
        }
        return res;
    }
};
