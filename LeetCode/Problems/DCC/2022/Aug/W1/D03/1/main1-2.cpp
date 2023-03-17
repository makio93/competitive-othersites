// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    map<int, int> cal;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        auto titr = cal.lower_bound(start);
        if (titr!=cal.end() && titr->first<end) return false;
        if (titr!=cal.begin() && prev(titr)->second>start) return false;
        cal[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
