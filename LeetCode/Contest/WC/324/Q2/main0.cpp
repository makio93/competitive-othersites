// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestValue(int n) {
        int nval = n;
        do {
            n = nval;
            nval = 0;
            int tmp = n;
            for (int i=2; i*i<=tmp; ++i) {
                while (tmp%i == 0) {
                    nval += i;
                    tmp /= i;
                }
            }
            if (tmp > 1) nval += tmp;
        } while (nval < n);
        return min(n, nval);
    }
};
