// 終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<tuple<double, double, int>> st;
        vector<double> res(n, -1.0);
        for (int i=n-1; i>=0; --i) {
            tuple<double, double, int> pre = { -1.0, -1.0, -1 };
            while (!st.empty() && (get<0>(st.top())-cars[i][0])/cars[i][1]>=get<1>(st.top())) {
                pre = st.top();
                st.pop();
            }
            if (get<2>(pre)!=-1 && cars[i][1]-cars[get<2>(pre)][1]>0) {
                double nxtx = (double)(cars[get<2>(pre)][0]-cars[i][0])*cars[i][1] / (cars[i][1]-cars[get<2>(pre)][1]);
                double nxtt = nxtx / cars[i][1];
                res[i] = nxtt;
                tuple<double, double, int> nxt = { cars[i][0]+nxtx, nxtt, get<2>(pre) }; 
                st.push(nxt);
            }
            st.emplace((double)cars[i][0], 0.0, i);
        }
        return res;
    }
};
