#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    int kmax;
    deque<int> que;
public:
    MyCircularQueue(int k) {
        kmax = k;
        que = deque<int>();
    }
    
    bool enQueue(int value) {
        if ((int)(que.size()) >= kmax) return false;
        else {
            que.push_back(value);
            return true;
        }
    }
    
    bool deQueue() {
        if (que.empty()) return false;
        else {
            que.pop_front();
            return true;
        }
    }
    
    int Front() {
        if (que.empty()) return -1;
        else return que.front();
    }
    
    int Rear() {
        if (que.empty()) return -1;
        else return que.back();
    }
    
    bool isEmpty() { return que.empty(); }
    
    bool isFull() { return (que.size() >= kmax); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){
    MyCircularQueue* obj = new MyCircularQueue(8);
    obj->enQueue(3);
    obj->enQueue(9);
    obj->enQueue(5);
    obj->enQueue(0);
    obj->deQueue();
    obj->deQueue();
    obj->isEmpty();
    obj->isEmpty();
    cout << obj->Rear() << endl;
    cout << obj->Rear() << endl;
    obj->deQueue();
    return 0;
}
