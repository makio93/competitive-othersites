#include <bits/stdc++.h>
using namespace std;

// 自力解答1,TLE

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n >= 4) {
            unordered_map<int, vector<int>> index;
            for (int i=0; i<n; ++i) index[nums[i]].push_back(i);
            set<vector<int>> memo;
            for (int a=0; a<n; ++a) for (int b=a+1; b<n; ++b) for (int c=b+1; c<n; ++c) {
                long long dval = (long long)target - nums[a] - nums[b] - nums[c];
                if (dval<(long long)(-1e9) || dval>(long long)(1e9) || index.find(dval)==index.end()) continue;
                bool ok = false;
                for (int id : index[dval]) {
                    bool ok2 = true;
                    for (int tid : { a, b, c }) if (id == tid) ok2 = false;
                    if (ok2) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) continue;
                vector<int> ires;
                for (int id : { a, b, c }) ires.push_back(nums[id]);
                ires.push_back(dval);
                sort(ires.begin(), ires.end());
                memo.insert(ires);
            }
            for (auto ires : memo) res.push_back(ires);
        }
        return res;
    }
};
