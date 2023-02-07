// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0;
        int li = 0, ri = n-1;
        while (li < k) {
            sum += cardPoints[li];
            ++li;
        }
        int res = sum;
        while (li-1 >= 0) {
            --li;
            sum -= cardPoints[li];
            sum += cardPoints[ri];
            --ri;
            res = max(res, sum);
        }
        return res;
    }
};
