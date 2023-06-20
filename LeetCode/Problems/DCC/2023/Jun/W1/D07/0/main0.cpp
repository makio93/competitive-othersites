// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i=0; i<30; ++i) {
            if ((c>>i)&1) { if (!((a>>i)&1) && !((b>>i)&1)) ++res; }
            else {
                if ((a>>i)&1) ++res;
                if ((b>>i)&1) ++res;
            }
        }
        return res;
    }
};
