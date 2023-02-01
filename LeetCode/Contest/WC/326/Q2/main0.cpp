// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> primes;
        for (int i1=0; i1<n; ++i1) {
            int tval = nums[i1];
            for (int i=2; i*i<=tval; ++i) if (tval%i == 0) {
                primes.insert(i);
                while (tval%i == 0) tval /= i;
            }
            if (tval > 1) primes.insert(tval);
        }
        return (int)(primes.size());
    }
};
