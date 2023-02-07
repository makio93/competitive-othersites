#include <bits/stdc++.h>
using namespace std;

/*
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 * 		      1 if num is higher than the guess number
 *               otherwise return 0
*/
int guess(int num);

// 自力AC

using ll = long long;
class Solution {
public:
    int guessNumber(int n) {
        ll l = 1, r = (ll)n + 1;
        while (r-l > 1) {
            ll c = (l + r) / 2;
            int ret = guess((int)c);
            if (ret == -1) r = c;
            else if (ret == 1) l = c + 1;
            else { l = c; r = c + 1; }
        }
        return (int)l;
    }
};
