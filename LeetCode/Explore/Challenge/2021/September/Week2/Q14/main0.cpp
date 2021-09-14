#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length(), li = 0, ri = n-1;
        while (li < ri) {
            while (!isalpha(s[li]) && li+1<n) ++li;
            while (!isalpha(s[ri]) && ri-1>=0) --ri;
            if (li < ri) swap(s[li], s[ri]);
            ++li; --ri;
        }
        return s;
    }
};
