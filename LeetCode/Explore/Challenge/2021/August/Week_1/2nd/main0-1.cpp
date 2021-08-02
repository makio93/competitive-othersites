#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:O(N*log(N))

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> index;
        for (int i=0; i<n; ++i) index[nums[i]].push_back(i);
        vector<int> res;
        for (auto p : index) {
            int tar = target - p.first;
            if (index.find(tar) != index.end()) {
                if (p.first != tar) {
                    res.push_back(p.second.front());
                    res.push_back(index[tar].front());
                }
                else if ((int)(index[tar].size()) > 1) {
                    res.push_back(p.second.front());
                    res.push_back(p.second[1]);
                }
            }
            if (!res.empty()) break;
        }
        return res;
    }
};
