#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for (int i=0; i<n; ++i) cardPoints.push_back(cardPoints[i]);
        for (int i=0; i+1<2*n; ++i) cardPoints[i+1] += cardPoints[i];
        int res = cardPoints[n-1] - (n-k-1>=0 ? cardPoints[n-k-1] : 0);
        for (int i=n; i-k<=n-1; ++i) res = max(res, cardPoints[i]-cardPoints[i-k]);
        return res;
    }
};
