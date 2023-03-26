// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size(), mv = *max_element(nums.begin(), nums.end());
        vector<bool> primes(mv+1, true);
        vector<int> plst;
        plst.push_back(0);
        primes[0] = primes[1] = false;
        for (int i=2; i<=mv; ++i) if (primes[i]) {
            plst.push_back(i);
            for (int j=i*2; j<=mv; j+=i) primes[j] = false;
        }
        bool ok = true;
        int plen = plst.size();
        for (int i=0; i<n; ++i) {
            if (i-1 < 0) {
                int id = lower_bound(plst.begin(), plst.end(), nums[i]) - plst.begin() - 1;
                nums[i] -= plst[id];
            }
            else {
                int id = lower_bound(plst.begin(), plst.end(), nums[i]-nums[i-1]) - plst.begin() - 1;
                if (id < 0) return false;
                nums[i] -= plst[id];
            }
        }
        return true;
    }
};
