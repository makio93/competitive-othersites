// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), id1 = 0, id2 = 0;
        for (int i=0; i<n; ++i) {
            pushed[id1++] = pushed[i];
            while (id1-1>=0 && id2<n && pushed[id1-1]==popped[id2]) --id1, ++id2;
        }
        return id2 == n;
    }
};
