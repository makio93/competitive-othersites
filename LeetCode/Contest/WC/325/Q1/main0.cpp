// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if (find(words.begin(), words.end(), target) == words.end()) return -1;
        int res = n, id = startIndex, tcnt = 0;
        while (words[id] != target) {
            id = (id + 1) % n;
            ++tcnt;
        }
        res = min(res, tcnt);
        id = startIndex, tcnt = 0;
        while (words[id] != target) {
            id = (id - 1 + n) % n;
            ++tcnt;
        }
        res = min(res, tcnt);
        return res;
    }
};
