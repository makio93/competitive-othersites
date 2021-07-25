#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> ctake;
        for (char c : sentence) ctake.insert(c);
        return ((int)(ctake.size()) == 26);
    }
};
