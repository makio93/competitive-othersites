#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) {
            if (i==j || i==k || j==k || (digits[i]*100+digits[j]*10+digits[k])%2!=0 || digits[i]==0) continue;
            res.push_back(digits[i]*100+digits[j]*10+digits[k]);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
