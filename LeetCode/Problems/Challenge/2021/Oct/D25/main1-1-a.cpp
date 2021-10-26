#include <bits/stdc++.h>
using namespace std;

// 解説AC1a,stackの代わりにvector使用

class MinStack {
    vector<int> vst, mst;
public:
    MinStack() {}
    void push(int val) {
        if (mst.empty() || val<=mst.back()) mst.push_back(val);
        vst.push_back(val);
    }
    void pop() {
        if (mst.back() == vst.back()) mst.pop_back();
        vst.pop_back();
    }
    int top() { return vst.back(); }
    int getMin() { return mst.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */