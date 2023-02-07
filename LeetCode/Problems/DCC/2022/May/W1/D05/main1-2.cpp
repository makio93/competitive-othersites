// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> que, tque;
public:
    MyStack() {}
    void push(int x) {
        tque.push(x);
        while (!que.empty()) {
            tque.push(que.front());
            que.pop();
        }
        swap(que, tque);
    }
    int pop() {
        int res = que.front();
        que.pop();
        return res;
    }
    int top() { return que.front(); }
    bool empty() { return que.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
