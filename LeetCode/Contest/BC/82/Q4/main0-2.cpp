// 本番TLE2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        for (int i=1; i*i<=threshold; ++i) {
            {
                int id = i, tval = threshold / id;
                deque<int> deq;
                for (int j=0; j<n; ++j) {
                    if (!deq.empty() && deq.front()<j-id+1) deq.pop_front();
                    while (!deq.empty() && nums[deq.back()]>=nums[j]) deq.pop_back();
                    deq.push_back(j);
                    if (j-id+1>=0 && nums[deq.front()]>tval) return id; 
                }
            }
            if (threshold/i <= n) {
                int id = threshold/i, tval = threshold / id;
                deque<int> deq;
                for (int j=0; j<n; ++j) {
                    if (!deq.empty() && deq.front()<j-id+1) deq.pop_front();
                    while (!deq.empty() && nums[deq.back()]>=nums[j]) deq.pop_back();
                    deq.push_back(j);
                    if (j-id+1>=0 && nums[deq.front()]>tval) return id; 
                }
            }
        }
        return -1;
    }
};
