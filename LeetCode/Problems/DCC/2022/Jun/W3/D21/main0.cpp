// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i=0; i+1<n; ++i) if (heights[i+1] > heights[i]) {
            int sub = heights[i+1] - heights[i];
            pq.push(sub);
            if ((int)(pq.size()) > ladders) {
                sum += pq.top();
                pq.pop();
            }
            if (sum > bricks) return i;
        }
        return n-1;
    }
};
