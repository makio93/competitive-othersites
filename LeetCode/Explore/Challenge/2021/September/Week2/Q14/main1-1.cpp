#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> alphas;
        for (char ci : s) if (isalpha(ci)) alphas.push(ci);
        for (char& ci : s) if (isalpha(ci)) { ci = alphas.top(); alphas.pop(); }
        return s;
    }
};
