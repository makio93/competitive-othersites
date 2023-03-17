// 自力AC

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    set<pair<int, int>> sches;
public:
    MyCalendar() {
        sches.emplace(0, -1);
    }
    bool book(int start, int end) {
        auto litr = sches.lower_bound({ start, 1 });
        if (prev(litr)->second != -1) return false;
        auto ritr = sches.lower_bound({ end, -1 });
        if (litr != ritr) return false;
        sches.emplace(start, 1);
        sches.emplace(end, -1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
