#include <bits/stdc++.h>
using namespace std;

// 自力AC

class MinStack {
    stack<int> st;
    map<int, int> mp;
public:
    MinStack() {}
    void push(int val) { st.push(val); mp[val]++; }
    void pop() {
        mp[st.top()]--;
        if (mp[st.top()] == 0) mp.erase(st.top());
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return mp.begin()->first; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */