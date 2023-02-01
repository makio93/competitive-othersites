// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        map<int, int> ncnt;
        vector<pair<int, int>> del;
        for (int i=0; i<n; ++i) {
            ncnt[i] = nums[i];
            if (i+1<n && nums[i+1]<nums[i]) del.emplace_back(i, i+1);
        }
        int res = 0;
        while (!del.empty()) {
            ++res;
            for (auto pi : del) ncnt.erase(pi.second);
            vector<pair<int, int>> ndel;
            for (auto pi : del) {
                auto itr = ncnt.find(pi.first);
                if (itr==ncnt.end() || next(itr)==ncnt.end()) continue;
                if (next(itr)->second < itr->second) ndel.emplace_back(itr->first, next(itr)->first); 
            }
            swap(del, ndel);
        }
        return res;
    }
};
