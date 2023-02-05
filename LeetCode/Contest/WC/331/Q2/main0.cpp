// 本番AC

#include <bits/stdc++.h>
using namespace std;

const string vowels = "aeiou";
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> vsum(n+1), ans(m);
        for (int i=0; i<n; ++i) {
            int add = 0;
            if (count(vowels.begin(), vowels.end(), words[i].front()) > 0 && count(vowels.begin(), vowels.end(), words[i].back()) > 0) 
                ++add;
            vsum[i+1] = vsum[i] + add;
        }
        for (int i=0; i<m; ++i) ans[i] = vsum[queries[i][1]+1] - vsum[queries[i][0]];
        return ans;
    }
};
