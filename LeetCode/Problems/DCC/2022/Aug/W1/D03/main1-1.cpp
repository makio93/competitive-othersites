// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    vector<pair<int, int>> sches;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        for (auto pi : sches) if (end>pi.first && start<pi.second) return false;
        sches.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
