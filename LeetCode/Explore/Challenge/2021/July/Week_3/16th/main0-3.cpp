#include <bits/stdc++.h>
using namespace std;

// 自力解答3,なぜかWAに

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n >= 4) {
            vector<int> l = { 0, n/2 }, r = { n/2, n };
            vector<vector<unordered_map<long long, set<multiset<int>>>>> mp(2, vector<unordered_map<long long, set<multiset<int>>>>(4));
            for (int j=0; j<2; ++j) {
                multiset<int> rst;
                for (int i0=l[j]; i0<r[j]; ++i0) {
                    long long sum0 = nums[i0];
                    rst.insert(nums[i0]);
                    if (mp[j][0].find(sum0)!=mp[j][0].end() && mp[j][0][sum0].find(rst)!=mp[j][0][sum0].end()) {
                        rst.erase(rst.find(nums[i0]));
                        continue;
                    }
                    mp[j][0][sum0].insert(rst);
                    for (int i1=i0+1; i1<r[j]; ++i1) {
                        long long sum1 = sum0 + nums[i1];
                        rst.insert(nums[i1]);
                        if (mp[j][1].find(sum1)!=mp[j][1].end() && mp[j][1][sum1].find(rst)!=mp[j][1][sum0].end()) {
                            rst.erase(rst.find(nums[i1]));
                            continue;
                        }
                        mp[j][1][sum1].insert(rst);
                        for (int i2=i1+1; i2<r[j]; ++i2) {
                            long long sum2 = sum1 + nums[i2];
                            rst.insert(nums[i2]);
                            if (mp[j][2].find(sum2)!=mp[j][2].end() && mp[j][2][sum2].find(rst)!=mp[j][2][sum2].end()) {
                                rst.erase(rst.find(nums[i2]));
                                continue;
                            }
                            mp[j][2][sum2].insert(rst);
                            for (int i3=i2+1; i3<r[j]; ++i3) {
                                long long sum3 = sum2 + nums[i3];
                                rst.insert(nums[i3]);
                                if (mp[j][3].find(sum3)!=mp[j][3].end() && mp[j][3][sum3].find(rst)!=mp[j][3][sum3].end()) {
                                    rst.erase(rst.find(nums[i3]));
                                    continue;
                                }
                                mp[j][3][sum3].insert(rst);
                                rst.erase(rst.find(nums[i3]));
                            }
                            rst.erase(rst.find(nums[i2]));
                        }
                        rst.erase(rst.find(nums[i1]));
                    }
                    rst.erase(rst.find(nums[i0]));
                }
            }
            set<multiset<int>> rst;
            for (int i=0; i<2; ++i) for (auto s : mp[i][3][(long long)(target)]) rst.insert(s);
            for (int i=0; i<3; ++i) for (auto p : mp[0][i]) {
                long long sval = (long long)target - p.first;
                if (mp[1][2-i].find(sval) != mp[1][2-i].end()) {
                    for (auto s0 : p.second) for (auto s1 : mp[1][2-i][sval]) {
                        multiset<int> irst = s0;
                        for (int s1i : s1) irst.insert(s1i);
                        rst.insert(irst);
                    }
                }
            }
            for (auto p : rst) {
                vector<int> ires;
                for (int val : p) ires.push_back(val);
                res.push_back(ires);
            }
        }
        return res;
    }
};
