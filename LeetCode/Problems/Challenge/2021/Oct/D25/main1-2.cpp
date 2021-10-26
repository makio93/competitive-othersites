#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {}
    void push(int val) {
        int mval = val;
        if (!st.empty()) mval = min(mval, st.top().second);
        st.emplace(val, mval);
    }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */