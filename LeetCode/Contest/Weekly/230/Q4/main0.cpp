// 本番WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n);
        ans[n-1] = -1;
        int slow = n-1;
        for (int i=n-2; i>=0; --i) {
            double nans = (1e9);
            if (cars[i][1]-cars[slow][1] > 0) {
                nans = min(nans, (double)(cars[slow][0]-cars[i][0])/(double)(cars[i][1]-cars[slow][1]));
            }
            if (cars[i][1]-cars[i+1][1] > 0) {
                nans = min(nans, (double)(cars[i+1][0]-cars[i][0])/(double)(cars[i][1]-cars[i+1][1]));
            }
            if (cars[i][1] <= cars[slow][1]) slow = i;
            if (nans == (1e9)) ans[i] = -1;
            else ans[i] = nans;
        }
        return ans;
    }
};
