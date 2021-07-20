#include <bits/stdc++.h>
using namespace std;

// 自力解答4,自力AC

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n >= 4) {
            sort(nums.begin(), nums.end());
            set<vector<int>> rst;
            unordered_map<int, set<int>> index;
            for (int i=0; i<n; ++i) index[nums[i]].insert(i);
            for (int a=0; a<n; ++a) if (a==0 || nums[a]!=nums[a-1]) for (int b=a+1; b<n; ++b) if (b==a+1 || nums[b]!=nums[b-1]) {
                for (int c=b+1; c<n; ++c) if (c==b+1 || nums[c]!=nums[c-1]) {
                    long long dval = (long long)target - nums[a] - nums[b] - nums[c];
                    if (dval<(long long)(-1e9) || dval>(long long)(1e9) || index.find((int)dval)==index.end()) continue;
                    int icnt = 0;
                    for (int id : { a, b, c }) if (index[(int)dval].find(id) != index[(int)(dval)].end()) ++icnt;
                    if (icnt >= (int)(index[(int)dval].size())) continue;
                    vector<int> tval;
                    for (int tid : { a, b, c }) tval.push_back(nums[tid]);
                    tval.push_back((int)dval);
                    sort(tval.begin(), tval.end());
                    rst.insert(tval);
                }
            }
            for (auto ri : rst) res.push_back(ri);
        }
        return res;
    }
};
