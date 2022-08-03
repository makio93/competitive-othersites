// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    map<int, int> sches;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        auto litr = sches.upper_bound(start), ritr = sches.lower_bound(start);
        if ((litr==sches.begin()||prev(litr)->second<=start) && (ritr==sches.end()||ritr->first>=end)) {
            sches[start] = end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
