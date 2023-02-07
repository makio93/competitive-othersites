// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length(), n2 = version2.length();
        vector<long long> rev1, rev2;
        int id = 0;
        for (int i=0; i<n1; ++i) {
            if (i+1>=n1 || version1[i+1]=='.') {
                rev1.push_back(stoll(version1.substr(id, i-id+1)));
                id = i+2;
            }
        }
        id = 0;
        for (int i=0; i<n2; ++i) {
            if (i+1>=n2 || version2[i+1]=='.') {
                rev2.push_back(stoll(version2.substr(id, i-id+1)));
                id = i+2;
            }
        }
        if (rev1.size() < rev2.size()) {
            int len = (int)(rev2.size()) - rev1.size();
            for (int i=0; i<len; ++i) rev1.push_back(0);
        }
        else if (rev2.size() < rev1.size()) {
            int len = (int)(rev1.size()) - rev2.size();
            for (int i=0; i<len; ++i) rev2.push_back(0);
        }
        return (rev1 > rev2) ? 1 : (rev2 > rev1) ? -1 : 0;
    }
};
