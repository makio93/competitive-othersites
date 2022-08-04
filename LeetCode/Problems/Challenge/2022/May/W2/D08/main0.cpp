// 自力AC

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
    vector<NestedInteger>* vptr;
    vector<NestedInteger>::iterator nitr;
    stack<pair<vector<NestedInteger>*, vector<NestedInteger>::iterator>> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        vptr = &nestedList; nitr = vptr->begin();
        norm();
    }
    void norm() {
        while ((nitr==vptr->end()&&!st.empty()) || (nitr!=vptr->end()&&!nitr->isInteger())) {
            while (nitr==vptr->end() && !st.empty()) {
                vptr = st.top().first;
                nitr = st.top().second; st.pop();
            }
            if (nitr==vptr->end() && st.empty()) break;
            while (nitr!=vptr->end() && !nitr->isInteger()) {
                st.emplace(vptr, std::next(nitr));
                vptr = const_cast<vector<NestedInteger>*>(&nitr->getList());
                nitr = vptr->begin();
            }
        }
    }
    int next() {
        int rval = nitr->getInteger();
        ++nitr;
        norm();
        return rval;
    }
    bool hasNext() { return !(nitr==vptr->end() && st.empty()); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
