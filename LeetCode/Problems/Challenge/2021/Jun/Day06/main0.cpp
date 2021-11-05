#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:O(N)解

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> ends;
        for (int i=0; i<n; ++i) {
            if (ends.find(nums[i]) != ends.end()) continue;
            if (ends.find(nums[i]+1)!=ends.end() || ends.find(nums[i]-1)!=ends.end()) {
                unordered_set<int> dids;
                if (ends.find(nums[i]+1)!=ends.end() && ends.find(nums[i]-1)!=ends.end()) dids.insert({ nums[i]+1, nums[i]-1, ends[nums[i]+1], ends[ends[nums[i]+1]], ends[nums[i]-1], ends[ends[nums[i]-1]] });
                else if (ends.find(nums[i]+1) != ends.end()) dids.insert({ nums[i], nums[i]+1, ends[nums[i]+1], ends[ends[nums[i]+1]] });
                else dids.insert({ nums[i], nums[i]-1, ends[nums[i]-1], ends[ends[nums[i]-1]] });
                int uval = (int)(-1.1e9), dval = (int)(1.1e9);
                for (int id : dids) {
                    uval = max(uval, id);
                    dval = min(dval, id);
                }
                ends[uval] = dval;
                ends[dval] = uval;
                res = max(res, abs(dval-uval)+1);
                for (int id : dids) if (id!=dval && id!=uval) ends.erase(id);
            }
            else {
                ends[nums[i]] = nums[i];
                res = max(res, 1);
            }
        }
        return res;
    }
};
