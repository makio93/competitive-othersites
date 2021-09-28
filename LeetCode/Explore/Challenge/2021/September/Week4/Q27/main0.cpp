#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ecnt;
        for (string ei : emails) {
            string loc = ei.substr(0U, ei.find('@')), dom = ei.substr(loc.length());
            loc = loc.substr(0U, loc.find('+'));
            string nloc;
            for (char ci : loc) if (ci != '.') nloc.push_back(ci);
            ecnt.insert(nloc+dom);
        }
        return (int)(ecnt.size());
    }
};
