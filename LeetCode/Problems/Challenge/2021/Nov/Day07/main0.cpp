#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        map<int, int> dvals;
        for (int i=0; i<n1; ++i) for (int j=0; j<n2; ++j) {
            dvals[i+j] += (int)(num1[i]-'0') * (int)(num2[j]-'0');
        }
        for (int i=0; i<n1+n2-1; ++i) {
            int ten = 0, tval = dvals[i];
            dvals[i] = 0;
            while (tval > 0) {
                dvals[i+ten] += tval % 10;
                tval /= 10;
                ++ten;
            }
        }
        string res;
        for (auto pi : dvals) res += (char)(pi.second+'0');
        while (res.back()=='0' && (int)(res.length())>1) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
