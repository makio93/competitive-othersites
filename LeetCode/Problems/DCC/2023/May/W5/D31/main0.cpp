// 自力AC

#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    map<pair<string, string>, pair<int, int>> procounts;
    unordered_map<int, pair<string, int>> processes;
public:
    UndergroundSystem() {}
    void checkIn(int id, string stationName, int t) {
        processes[id] = { stationName, t };
    }
    void checkOut(int id, string stationName, int t) {
        procounts[{ processes[id].first, stationName }].first += t - processes[id].second;
        procounts[{ processes[id].first, stationName }].second++;
        processes.erase(id);
    }
    double getAverageTime(string startStation, string endStation) {
        return (double)procounts[{ startStation, endStation }].first / procounts[{ startStation, endStation }].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
