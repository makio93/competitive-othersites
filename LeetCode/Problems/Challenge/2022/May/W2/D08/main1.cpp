// 解説AC

#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    stack<vector<NestedInteger>::iterator> llst, rlst;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        llst.push(nestedList.begin());
        rlst.push(nestedList.end());
    }
    int next() {
        if (hasNext()) {
            int rval = llst.top()->getInteger();
            llst.top()++;
            return rval;
        }
        return 0;
    }
    bool hasNext() {
        while (!llst.empty()) {
            if (llst.top() == rlst.top()) {
                llst.pop();
                rlst.pop();
            }
            else {
                if (llst.top()->isInteger()) return true;
                auto itr = llst.top();
                llst.top()++;
                llst.push(itr->getList().begin());
                rlst.push(itr->getList().end());
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
