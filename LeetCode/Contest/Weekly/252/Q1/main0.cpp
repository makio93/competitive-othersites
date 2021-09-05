#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i=1; i*i<=n; ++i) if (n%i == 0) {
            if (i == n/i) ++cnt;
            else cnt += 2;
        }
        return (cnt == 3);
    }
};
