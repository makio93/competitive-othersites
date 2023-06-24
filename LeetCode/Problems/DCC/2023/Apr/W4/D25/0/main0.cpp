// 自力AC

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    set<int> st;
    int li;
public:
    SmallestInfiniteSet() { li = 1; }
    int popSmallest() {
        st.insert(li);
        int ret = li;
        while (st.find(li) != st.end()) ++li;
        return ret;
    }
    void addBack(int num) {
        if (st.find(num) == st.end()) return;
        st.erase(num);
        if (num < li) li = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
