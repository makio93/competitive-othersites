#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), m = queries.size();
        vector<int> ans(m);
        for (int i=0; i<m; ++i) {
            int dr = queries[i][2] * queries[i][2], cnt = 0;
            for (int j=0; j<n; ++j) {
                int dx = (queries[i][0]-points[j][0]) * (queries[i][0]-points[j][0]);
                int dy = (queries[i][1]-points[j][1]) * (queries[i][1]-points[j][1]);
                if (dx + dy <= dr) ++cnt;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
