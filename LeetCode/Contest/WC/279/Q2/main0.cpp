#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    long long smallestNumber(long long num) {
        long long res = 0;
        if (num > 0LL) {
            string tmp = to_string(num);
            sort(tmp.begin(), tmp.end());
            int m = tmp.length();
            for (int i=0; i<m; ++i) if (tmp[i] != '0') {
                swap(tmp[i], tmp[0]);
                break;
            }
            res = stoll(tmp);
        }
        else if (num < 0LL) {
            string tmp = to_string(abs(num));
            sort(tmp.rbegin(), tmp.rend());
            res = stoll(tmp) * -1;
        }
        return res;
    }
};
