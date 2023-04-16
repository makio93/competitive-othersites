// 本番AC

#include <bits/stdc++.h>
using namespace std;

const string tar = "abc";
class Solution {
public:
    int addMinimum(string word) {
        int n = word.length(), res = 0, id = 2;
        for (int i=0; i<n; ++i) {
            id = (id+1) % 3;
            while (word[i] != tar[id]) {
                ++res;
                id = (id+1) % 3;
            }
        }
        while (id != 2) {
            ++res;
            id = (id+1) % 3;
        }
        return res;
    }
};
