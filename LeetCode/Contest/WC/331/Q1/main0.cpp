// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for (int i=0; i<k; ++i) {
            int id = max_element(gifts.begin(), gifts.end()) - gifts.begin();
            gifts[id] = (int)floor(sqrt(gifts[id]));
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
