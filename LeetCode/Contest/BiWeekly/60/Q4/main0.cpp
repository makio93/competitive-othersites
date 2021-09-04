#include <bits/stdc++.h>
using namespace std;

// 本番WA

class Solution {
    const long long mod = (long long)(1e9) + 7;
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        map<set<int>, int> scnt;
        scnt[set<int>({})] = 1;
        long long res = 0;
        for (int i=0; i<n; ++i) {
            map<set<int>, int> add;
            if (nums[i] == 1) {
                for (auto& p : scnt) add[p.first] = p.second;
                for (auto p : add) {
                    if (scnt.find(p.first) == scnt.end()) scnt[p.first] = p.second;
                    else scnt[p.first] = (scnt[p.first] + p.second) % mod;
                }
            }
            else {
                vector<pair<int, int>> primes;
                int val = nums[i];
                bool ok = true;
                for (int i=2; i*i<=val; ++i) if (val%i == 0) {
                    primes.emplace_back(i, 0);
                    while (val%i == 0) {
                        val /= i;
                        primes.back().second++;
                    }
                    if (primes.back().second > 1) ok = false;
                }
                if (val > 1) primes.emplace_back(val, 1);
                if (!ok) continue;
                for (auto& p : scnt) {
                    bool ok2 = true;
                    for (auto p2 : primes) if (p.first.find(p2.first) != p.first.end()) {
                        ok2 = false;
                        break;
                    }
                    if (!ok2) continue;
                    set<int> tmp = p.first;
                    for (auto p2 : primes) tmp.insert(p2.first);
                    add[tmp] = p.second;
                }
                for (auto p : add) {
                    if (scnt.find(p.first) == scnt.end()) scnt[p.first] = p.second;
                    else scnt[p.first] = (scnt[p.first] + p.second) % mod;
                }
            }
        }
        for (auto p : scnt) if (p.first != set<int>({})) res = (res + p.second) % mod;
        return res;
    }
};
