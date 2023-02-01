// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> dict;
        for (char& ci : key) if (ci!=' ' && dict.find(ci)==dict.end()) {
            dict[ci] = (char)(dict.size()+'a');
        }
        for (char& ci : message) if (ci != ' ') ci = dict[ci];
        return message;
    }
};
