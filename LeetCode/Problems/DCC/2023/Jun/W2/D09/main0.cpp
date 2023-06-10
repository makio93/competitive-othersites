// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto itr = upper_bound(letters.begin(), letters.end(), target);
        if (itr == letters.end()) return *letters.begin();
        else return *itr;
    }
};
