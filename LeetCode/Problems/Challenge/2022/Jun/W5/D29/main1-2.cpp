// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& vl, auto& vr) -> bool {
            return vl[0] != vr[0] ? vl[0] < vr[0] : vl[1] > vr[1];
        });
        vector<int> pcnt(n, 1);
        vector<vector<int>> res(n);
        for (auto& vi : people) {
            int sum = 0;
            for (int j=0; j<n; ++j) if (pcnt[j] == 1) {
                if (sum == vi[1]) {
                    res[j] = vi;
                    pcnt[j]--;
                    break;
                }
                sum += pcnt[j];
            }
        }
        return res;
    }
};
