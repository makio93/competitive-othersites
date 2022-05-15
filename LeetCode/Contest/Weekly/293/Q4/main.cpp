// 

#include <bits/stdc++.h>
using namespace std;

class CountIntervals {
    int cnt;
    map<int, int> lr;
public:
    CountIntervals() {
        cnt = 0;
    }
    void add(int left, int right) {
        int li = left, ri = right + 1;
        if (!lr.empty()) {
            auto itr1 = lr.lower_bound(li);
            if (itr1!=lr.end() && itr1->second==-1) {
                int val1 = prev(itr1)->first;
                li = min(li, val1);
            }
            auto itr2 = lr.upper_bound(ri);
            if (itr2!=lr.end() && itr2->second==-1) {
                int val2 = itr2->first;
                ri = max(ri, val2);
            }
            for (auto itr=lr.lower_bound(li); itr!=lr.end()&&itr->first<=ri; ) {
                int tr = next(itr)->first;
                cnt -= tr - itr->first;
                itr = lr.erase(itr);
                itr = lr.erase(itr);
            }
        }
        lr[li] = 1;
        lr[ri] = -1;
        cnt += ri - li;
    }
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
