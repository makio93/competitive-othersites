// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> items;
        for (int i=0; i<numOnes; ++i) items.push_back(1);
        for (int i=0; i<numZeros; ++i) items.push_back(0);
        for (int i=0; i<numNegOnes; ++i) items.push_back(-1);
        return accumulate(items.begin(), items.begin()+k, 0);
    }
};
