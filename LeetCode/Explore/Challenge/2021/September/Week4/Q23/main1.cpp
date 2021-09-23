#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n == 1) return string("");
        for (int i=0; i<n/2; ++i) if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};
