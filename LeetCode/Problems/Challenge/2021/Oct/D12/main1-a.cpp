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

// 解説実装1,総当たり解,TLE

using ll = long long;
class Solution {
public:
    int guessNumber(int n) {
        int rval = n, val = 1;
        while (guess((int)val)!=0 && val<=rval) ++val;
        return val;
    }
};
