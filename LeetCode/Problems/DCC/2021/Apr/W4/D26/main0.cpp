#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        multiset<pair<int, int>> st;
        unordered_map<int, int> vcnt;
        st.emplace(0, vcnt[0]+1);
        vcnt[0]++;
        auto itr = st.begin();
        int bsum = 0;
        bool ful = false;
        for (int i=0; i<n-1; ++i) if (heights[i+1] > heights[i]) {
            int val = heights[i+1] - heights[i];
            st.emplace(val, vcnt[val]+1);
            vcnt[val]++;
            if (!ful && (int)(st.size())>ladders+1) ful = true;
            if (ful) {
                if (make_pair(val,vcnt[val]) >= *itr) {
                    ++itr;
                    bsum += itr->first;
                }
                else bsum += val;
            }
            else itr = st.begin();
            if (ful && bsum>bricks) return i;
        }
        return n-1;
    }
};
