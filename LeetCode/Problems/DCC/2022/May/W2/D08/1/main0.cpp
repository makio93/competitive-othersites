// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    vector<NestedInteger> *ptr;
    vector<NestedInteger>::iterator itr;
    NestedIterator *child;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        ptr = &nestedList;
        itr = ptr->begin();
        child = NULL;
    }
    int next() {
        if (itr->isInteger()) {
            ++itr;
            return prev(itr)->getInteger();
        }
        else return child->next();
    }
    bool hasNext() {
        if (child != NULL) {
            if (child->hasNext()) return true;
            delete child;
            child = NULL;
            ++itr;
        }
        while (itr!=ptr->end() && !itr->isInteger()) {
            child = new NestedIterator(const_cast<vector<NestedInteger>&>(itr->getList()));
            if (child->hasNext()) return true;
            delete child;
            child = NULL;
            ++itr;
        }
        if (itr == ptr->end()) return false;
        else return true;
    }
};
