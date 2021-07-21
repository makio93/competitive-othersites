#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.length();
        vector<int> cid(26, -1), sid;
        for (int i=0; i<n; ++i) cid[(int)(order[i]-'a')] = i;
        string tail;
        for (char c : s) {
            if (cid[(int)(c-'a')] != -1) sid.push_back(cid[(int)(c-'a')]);
            else tail += c;
        }
        sort(sid.begin(), sid.end());
        sort(tail.begin(), tail.end());
        string res;
        for (int id : sid) res += order[id];
        res += tail;
        return res;
    }
};
