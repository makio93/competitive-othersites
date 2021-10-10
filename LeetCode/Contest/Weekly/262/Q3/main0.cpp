#include <bits/stdc++.h>
using namespace std;

// 本番AC

class StockPrice {
    map<int, int> ttop;
    map<int, unordered_set<int>> ptot;
public:
    StockPrice() {
        ttop = map<int, int>();
        ptot = map<int, unordered_set<int>>();
    }
    void update(int timestamp, int price) {
        if (ttop.find(timestamp) != ttop.end()) {
            int oldprice = ttop[timestamp];
            ptot[oldprice].erase(timestamp);
            if (ptot[oldprice].empty()) ptot.erase(oldprice);
        }
        ttop[timestamp] = price;
        ptot[price].insert(timestamp);
    }
    int current() { return ttop.rbegin()->second; }
    int maximum() { return ptot.rbegin()->first; }
    int minimum() { return ptot.begin()->first; }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
