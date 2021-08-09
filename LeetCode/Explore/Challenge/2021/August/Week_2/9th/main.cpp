#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length(), len = max(n1, n2);
        vector<int> digits(len+1);
        for (int i=0; i<n1; ++i) digits[len-i] += num1[n1-i-1] - '0';
        for (int i=0; i<n2; ++i) digits[len-i] += num2[n2-i-1] - '0';
        for (int i=len; i>0; --i) {
            digits[i-1] += digits[i] / 10;
            digits[i] %= 10;
        }
        string res;
        int id = 0;
        while (digits[id]==0 && id+1<=len) ++id;
        for (int i=id; i<=len; ++i) res += (char)(digits[i]+'0');
        return res;
    }
};
