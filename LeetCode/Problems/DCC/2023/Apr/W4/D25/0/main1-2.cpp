// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    set<int> st;
    int now;
public:
    SmallestInfiniteSet() { now = 1; }
    int popSmallest() {
        if (st.empty()) return now++;
        else {
            int res = *st.begin();
            st.erase(st.begin());
            return res;
        }
    }
    void addBack(int num) {
        if (num>=now || st.find(num)!=st.end()) return;
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
