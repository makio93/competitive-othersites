// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size(), res = 1;
        while ((res+1)*(res+2)/2 <= n) ++res;
        return res;
    }
};
