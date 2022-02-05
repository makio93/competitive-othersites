#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        map<int, int> vals;
        vector<unordered_map<int, int>> sub(n+1);
        vals[0]++;
        sub[1][0]--;
        sub[1][1]++;
        sub[min(n,nums[0]+1)][1]--;
        for (int i=1; i<n; ++i) {
            for (auto pi : sub[i]) {
                vals[pi.first] += pi.second;
                if (vals[pi.first] == 0) vals.erase(pi.first);
            }
            sub[i+1][vals.begin()->first+1]++;
            int ri = min(n,i+nums[i]+1);
            sub[ri][vals.begin()->first+1]--;
        }
        return vals.begin()->first;
    }
};
