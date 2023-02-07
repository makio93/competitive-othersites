// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> que;
public:
    MyStack() {}
    void push(int x) {
        que.push(x);
        int cnt = que.size() - 1;
        while (cnt) {
            que.push(que.front());
            que.pop();
            --cnt;
        }
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
