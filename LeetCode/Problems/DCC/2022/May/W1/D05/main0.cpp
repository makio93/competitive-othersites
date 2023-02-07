// 自力AC

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> que, tque;
public:
    MyStack() {}
    void push(int x) { que.push(x); }
    int pop() {
        while ((int)(que.size()) > 1) {
            tque.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        swap(que, tque);
        return res;
    }
    int top() {
        int res = pop();
        push(res);
        return res;
    }
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
