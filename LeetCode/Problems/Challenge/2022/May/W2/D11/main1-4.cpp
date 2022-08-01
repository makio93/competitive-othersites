// 解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4) * (n+3) * (n+2) * (n+1) / 24;
    }
};
