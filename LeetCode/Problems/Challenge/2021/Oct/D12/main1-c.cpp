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

// 解説実装3,三分探索解,AC

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int c1 = l + (r-l) / 3, c2 = r - (r-l) / 3;
            int r1 = guess(c1), r2 = guess(c2);
            if (r1 == 0) return c1;
            else if (r2 == 0) return c2;
            else if (r1 == -1) r = c1 - 1;
            else if (r2 == 1) l = c2 + 1;
            else { l = c1+1; r = c2-1; }
        }
        return -1;
    }
};
