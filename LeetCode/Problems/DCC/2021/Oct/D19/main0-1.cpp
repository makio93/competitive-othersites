#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:O(N*M)解法

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);
        for (int i=0; i<n; ++i) {
            int jid = -1;
            for (int j=0; j<m; ++j) if (nums1[i] == nums2[j]) { jid = j; break; }
            for (int j=jid+1; j<m; ++j) if (nums2[j] > nums2[jid]) { ans[i] = nums2[j]; break; }
        }
        return ans;
    }
};
