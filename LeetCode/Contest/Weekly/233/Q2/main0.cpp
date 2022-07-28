// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int n = orders.size();
        map<int, long long> sell, buy;
        for (int i=0; i<n; ++i) {
            if (orders[i][2] == 0) {
                int rest = orders[i][1];
                auto itr = sell.begin();
                while (itr != sell.end()) {
                    if (itr->first > orders[i][0]) break;
                    if (itr->second <= rest) {
                        rest -= itr->second;
                        itr = sell.erase(itr);
                    }
                    else {
                        itr->second -= rest;
                        rest = 0;
                        break;
                    }
                }
                if (rest > 0) buy[-orders[i][0]] += rest;
            }
            else {
                int rest = orders[i][1];
                auto itr = buy.begin();
                while (itr != buy.end()) {
                    if (itr->first > -orders[i][0]) break;
                    if (itr->second <= rest) {
                        rest -= itr->second;
                        itr = buy.erase(itr);
                    }
                    else {
                        itr->second -= rest;
                        rest = 0;
                        break;
                    }
                }
                if (rest > 0) sell[orders[i][0]] += rest;
            }
        }
        long long sum = 0LL;
        const long long mod = (long long)(1e9)+7;
        for (auto item : buy) sum = (sum + item.second) % mod;
        for (auto item : sell) sum = (sum + item.second) % mod;
        return (int)sum;
    }
};
