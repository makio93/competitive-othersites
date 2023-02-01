#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.length();
        vector<int> vals;
        int li = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == ' ') {
                if (isdigit(s[li])) vals.push_back(stoi(s.substr(li, i-li)));
                li = i + 1;
            }
            else if (i == n-1) {
                if (isdigit(s[li])) vals.push_back(stoi(s.substr(li, i-li+1)));
            }
        }
        int m = vals.size();
        for (int i=0; i<m-1; ++i) if (vals[i+1] <= vals[i]) return false;
        return true;
    }
};
