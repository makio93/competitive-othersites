#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class MinStack {
    stack<int> vst, mst;
public:
    MinStack() {}
    void push(int val) {
        if (mst.empty() || val<=mst.top()) mst.push(val);
        vst.push(val);
    }
    void pop() {
        if (mst.top() == vst.top()) mst.pop();
        vst.pop();
    }
    int top() { return vst.top(); }
    int getMin() { return mst.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */