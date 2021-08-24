#include <bits/stdc++.h>
using namespace std;

// 自力WA,2

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        word1 += (char)('a'-1);
        word2 += (char)('a'-1);
        string ans = "";
        int i1 = 0, i2 = 0;
        while (i1<n1 && i2<n2) {
            if (word1[i1] > word2[i2]) {
                ans += word1[i1];
                ++i1;
            }
            else if (word1[i1] < word2[i2]) {
                ans += word2[i2];
                ++i2;
            }
            else {
                ans += word1[i1];
                ans += word2[i2];
                ++i1; ++i2;
            }
        }
        if (i1 < n1) ans += word1.substr(i1, n1-i1);
        else if (i2 < n2) ans += word2.substr(i2, n2-i2);
        return ans;
    }
};
