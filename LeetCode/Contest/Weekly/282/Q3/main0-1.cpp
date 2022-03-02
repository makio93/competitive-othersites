// バチャ本番WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(), time.end());
        long long res = 0, tar = 0;
        for (int i=0; i<n; ++i) tar += time[i];
        tar = tar * totalTrips / n;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i=0; i<n; ++i) {
            long long tval = min((long long)totalTrips, tar/time[i]);
            totalTrips -= tval;
            res = max(res, tval*time[i]);
            pq.emplace(tval*time[i]+time[i], i);
            if (totalTrips == 0) break;
        }
        while (totalTrips > 0) {
            long long ti = pq.top().first;
            int id = pq.top().second; pq.pop();
            res = max(res, ti);
            int sval = (res - ti) / time[id];
            long long add = (long long)sval * time[id] + time[id];
            pq.emplace(ti+add, id);
            totalTrips -= sval;
        }
        return res;
    }
};
