#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mval = 0, psize = 0;
    int dfs(set<int>& primes, set<int>& nlst, int d=0, int bval=1) {
        if (d == psize) {
            if (nlst.find(bval) != nlst.end()) return 1;
            else return 0;
        }
        else {
            int npval = 0, nval = bval, aval = 1, res = 0;
            auto itr = primes.begin();
            if (d > 0) npval = *next(itr, d);
            else npval = *itr;
            while (nval*aval <= mval) {
                res += dfs(primes, nlst, d+1, nval*aval);
                aval *= npval;
            }
            return res;
        }
    }
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        set<int> primes, nlst;
        for (int i=0; i<n; ++i) {
            int tval = nums[i];
            for (int j=2; j*j<=tval; ++j) {
                if (tval%j==0) primes.insert(j);
                while (tval%j==0) tval /= j;
            }
            if (tval > 1) primes.insert(tval);
        }
        for (int i=0; i<n; ++i) mval = max(mval, nums[i]);
        for (int i=0; i<n; ++i) nlst.insert(nums[i]);
        psize = primes.size();
        int res = dfs(primes, nlst);
        return res;
    }
};

int main(){
    
    return 0;
}
