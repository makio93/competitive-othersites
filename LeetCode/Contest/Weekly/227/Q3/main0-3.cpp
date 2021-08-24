#include <bits/stdc++.h>
using namespace std;

// 自力WA,3

class Solution {
    const int mlen = (int)(3e3) + 5;
    string str1, str2;
    int len1, len2;
    unordered_map<int, string> memo;
    string calc(int n1, int n2) {
        int nid = n1 * mlen + n2;
        if (memo.find(nid) != memo.end()) return memo[nid];
        if (n1==0 && n2==0) return (memo[nid] = "");
        else if (n1 == 0) return (memo[nid] = calc(n1, n2-1) + str2[n2-1]);
        else if (n2 == 0) return (memo[nid] = calc(n1-1, n2) + str1[n1-1]);
        else {
            string res1 = calc(n1-1, n2) + str1[n1-1], res2 = calc(n1, n2-1) + str2[n2-1];
            return (memo[nid] = (res1 >= res2) ? res1 : res2);
        }
    }
public:
    string largestMerge(string word1, string word2) {
        len1 = word1.length(), len2 = word2.length();
        str1 = word1; str2 = word2;
        return calc(len1, len2);
    }
};
