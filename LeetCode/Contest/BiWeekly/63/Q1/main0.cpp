#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        vector<int> cnt1(100), cnt2(100);
        for (int i=0; i<n; ++i) cnt1[seats[i]-1]++;
        for (int i=0; i<n; ++i) cnt2[students[i]-1]++;
        vector<int> sub1, sub2;
        for (int i=0; i<100; ++i) if (cnt1[i] > cnt2[i]) {
            for (int j=0; j<cnt1[i]-cnt2[i]; ++j) sub1.push_back(i);
        }
        for (int i=0; i<100; ++i) if (cnt2[i] > cnt1[i]) {
            for (int j=0; j<cnt2[i]-cnt1[i]; ++j) sub2.push_back(i);
        }
        sort(sub1.begin(), sub1.end());
        sort(sub2.begin(), sub2.end());
        int res = 0, m = sub1.size();
        for (int i=0; i<m; ++i) res += abs(sub2[i]-sub1[i]);
        return res;
    }
};
