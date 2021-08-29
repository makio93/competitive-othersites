#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        map<int, vector<string>> strs;
        for (int i=0; i<n; ++i) strs[nums[i].length()].push_back(nums[i]);
        int cnt = 0;
        string res;
        for (auto itr=strs.rbegin(); itr!=strs.rend(); ++itr) {
            sort(itr->second.rbegin(), itr->second.rend());
            int mi = itr->second.size();
            if (cnt+mi < k) cnt += mi;
            else {
                res = itr->second[k-cnt-1];
                break;
            }
        }
        return res;
    }
};
