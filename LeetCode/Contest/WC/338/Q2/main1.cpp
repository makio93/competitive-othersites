// 解説AC

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
            for (int j=i*i; j<=mv; j+=i) primes[j] = false;
        }
        bool ok = true;
        int plen = plst.size();
        for (int i=0; i<n; ++i) {
            int sub = (i-1 < 0) ? 0 : nums[i-1], id = -1;
            while (id+1 < plen) {
                if (plst[id+1] >= nums[i]-sub) break;
                ++id;
            }
            if (id < 0) return false;
            nums[i] -= plst[id];
        }
        return true;
    }
};
