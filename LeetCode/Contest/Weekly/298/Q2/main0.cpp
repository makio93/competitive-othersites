// 本番AC

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if ((num%10)%gcd(k,10) != 0) return -1;
        if (k == 0) return 1;
        else {
            int lcnt = 1, sum = k;
            while (sum%10 != num%10) {
                sum += k;
                ++lcnt;
            }
            int lval = lcnt * k;
            if (lval > num) return -1;
            else return lcnt;
        }
    }
};
