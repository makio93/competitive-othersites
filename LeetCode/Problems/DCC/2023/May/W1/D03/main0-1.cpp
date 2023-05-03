// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        int n = nums1.size(), m = nums2.size(), li = 0, ri = 0;
        vector<vector<int>> res(2);
        while (li<n || ri<m) {
            if (li >= n) {
                res[1].push_back(nums2[ri]);
                ++ri;
            }
            else if (ri >= m) {
                res[0].push_back(nums1[li]);
                ++li;
            }
            else {
                if (nums1[li] < nums2[ri]) {
                    res[0].push_back(nums1[li]);
                    ++li;
                }
                else if (nums1[li] > nums2[ri]) {
                    res[1].push_back(nums2[ri]);
                    ++ri;
                }
                else {
                    ++li; ++ri;
                }
            }
        }
        return res;
    }
};
