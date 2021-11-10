#include <bits/stdc++.h>
using namespace std;

// 自力AC,別解

class MyCalendar {
    multiset<int> starts, ends;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        int scnt1 = distance(starts.begin(), starts.upper_bound(start)), scnt2 = distance(ends.begin(), ends.upper_bound(start));
        int ecnt = distance(starts.begin(), starts.upper_bound(end-1));
        if (scnt1!=scnt2 || scnt1!=ecnt || scnt2!=ecnt) return false;
        starts.insert(start);
        ends.insert(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
