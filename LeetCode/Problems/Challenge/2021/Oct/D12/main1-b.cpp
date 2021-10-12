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

// 解説実装2,二分探索解,AC

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int c = l + (r-l) / 2;
            int ret = guess((int)c);
            if (ret == 0) return c;
            else if (ret == -1) r = c - 1;
            else l = c + 1;
        }
        return -1;
    }
};
