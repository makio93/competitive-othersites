// 解説AC

#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    unordered_map<string, pair<int, int>> procounts;
    unordered_map<int, pair<string, int>> processes;
public:
    UndergroundSystem() {}
    void checkIn(int id, string stationName, int t) {
        processes[id] = { stationName, t };
    }
    void checkOut(int id, string stationName, int t) {
        string routeName = processes[id].first + '-' + stationName;
        procounts[routeName].first += t - processes[id].second;
        procounts[routeName].second++;
        processes.erase(id);
    }
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + '-' + endStation;
        return (double)procounts[routeName].first / procounts[routeName].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
