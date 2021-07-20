#include <bits/stdc++.h>
using namespace std;

// 自力解答2,自力AC,実行時間ギリギリ

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n >= 4) {
            unordered_map<int, vector<int>> index;
            set<vector<int>> three, choosed;
            for (int i=0; i<n; ++i) index[nums[i]].push_back(i);
            for (int a=0; a<n; ++a) for (int b=a+1; b<n; ++b) for (int c=b+1; c<n; ++c) {
                vector<int> tval;
                for (int tid : { a, b, c }) tval.push_back(nums[tid]);
                sort(tval.begin(), tval.end());
                if (three.find(tval) != three.end()) continue;
                three.insert(tval);
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
                tval.push_back(dval);
                sort(tval.begin(), tval.end());
                if (choosed.find(tval) != choosed.end()) continue;
                choosed.insert(tval);
            }
            for (auto resi : choosed) res.push_back(resi);
        }
        return res;
    }
};
