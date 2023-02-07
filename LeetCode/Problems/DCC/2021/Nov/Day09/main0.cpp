#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size(), m = puzzles.size();
        vector<bitset<100000>> ccnts(26);
        for (int i=0; i<n; ++i) for (char ci : words[i]) ccnts[ci-'a'][i] = 1;
        vector<int> res(m);
        for (int i=0; i<m; ++i) {
            auto tcnt = ccnts[puzzles[i][0]-'a'];
            for (int j=0; j<26; ++j) if (puzzles[i].find((char)(j+'a')) == string::npos) tcnt &= ~ccnts[j];
            res[i] = tcnt.count();
        }
        return res;
    }
};
