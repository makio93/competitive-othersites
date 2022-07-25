// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string ans = "";
        for (int i=0; i<min(n1,n2); ++i) {
            ans += word1[i];
            ans += word2[i];
        }
        if (n1 > n2) ans += word1.substr(n2, n1-n2);
        else if (n2 > n1) ans += word2.substr(n1, n2-n1);
        return ans;
    }
};
