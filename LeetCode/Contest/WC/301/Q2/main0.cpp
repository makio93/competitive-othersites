// 本番AC

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    set<int> vals;
public:
    SmallestInfiniteSet() {
        for (int i=1; i<=1100; ++i) vals.insert(i);
    }
    int popSmallest() {
        int val = *vals.begin();
        vals.erase(val);
        return val;
    }
    void addBack(int num) {
        vals.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
