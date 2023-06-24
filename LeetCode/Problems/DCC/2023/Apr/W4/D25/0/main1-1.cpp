// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    int now;
public:
    SmallestInfiniteSet() { now = 1; }
    int popSmallest() {
        if (st.empty()) return now++;
        else {
            int res = pq.top(); pq.pop();
            st.erase(res);
            return res;
        }
    }
    void addBack(int num) {
        if (num>=now || st.find(num)!=st.end()) return;
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
