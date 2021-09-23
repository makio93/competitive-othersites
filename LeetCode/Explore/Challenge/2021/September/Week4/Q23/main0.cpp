#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n == 1) return (string)("");
        else if (palindrome == string(n, 'a')) {
            palindrome.back() = 'b';
            return palindrome;
        }
        else {
            for (int i=0; i<n; ++i) if (palindrome[i] != 'a') {
                if (n%2==1 && i==n/2) palindrome.back() = (palindrome.back()=='b') ? 'a' : 'b';
                else palindrome[i] = 'a';
                break;
            }
            return palindrome;
        }
    }
};
