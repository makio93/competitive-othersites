#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long res = 0, sum = 0;
        while (sum < neededApples) {
            ++res;
            long long add = res * 4 + ((res+1)+(2*res-1)) * (res-1) / 2 * 8 + 2 * res * 4;
            sum += add;
        }
        return res * 8;
    }
};
