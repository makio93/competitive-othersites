#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    deque<int> dq;
public:
    MedianFinder() {
        dq.push_back((int)(-1e5)-5);
        dq.push_back((int)(1e5)+5);
    }
    
    void addNum(int num) {
        dq.insert(lower_bound(dq.begin(), dq.end(), num), num);
    }
    
    double findMedian() {
        int ct = ((int)(dq.size()) - 1) / 2;
        if ((int)(dq.size())%2 == 0) return (dq[ct]+dq[ct+1]) / 2.0;
        else return (double)dq[ct];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    return 0;
}
