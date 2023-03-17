// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    map<int, bool> memory;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        auto litr = memory.upper_bound(start), ritr = memory.lower_bound(end);
        if (litr!=ritr || (litr!=memory.end() && !litr->second)) return false;
        if (memory.find(start) != memory.end()) memory.erase(start);
        else memory[start] = true;
        if (memory.find(end) != memory.end()) memory.erase(end);
        else memory[end] = false;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
