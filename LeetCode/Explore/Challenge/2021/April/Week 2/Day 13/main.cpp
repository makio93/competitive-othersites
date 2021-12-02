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
    vector<NestedInteger>* nlitr;
    vector<NestedInteger>::iterator nitr;
public:
    NestedIterator* sublst = nullptr;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nlitr = &nestedList;
        nitr = nlitr->begin();
        while (1) {
            while (nitr!=nlitr->end() && !nitr->isInteger() && nitr->getList().empty()) ++nitr;
            if (nitr!=nlitr->end() && !nitr->isInteger()) {
                sublst = new NestedIterator((vector<NestedInteger>&)nitr->getList());
                if (!sublst->hasNext()) {
                    delete sublst;
                    ++nitr;
                    continue;
                }
            }
            break;
        }
    }
    int next() {
        int res = 0;
        if (nitr != nlitr->end()) {
            bool move = true;
            if (!nitr->isInteger()) {
                res = sublst->next();
                if (!sublst->hasNext()) {
                    delete sublst;
                    ++nitr;
                }
                else move = false;
            }
            else {
                res = nitr->getInteger();
                ++nitr;
            }
            if (move) {
                while (1) {
                    while (nitr!=nlitr->end() && !nitr->isInteger() && nitr->getList().empty()) ++nitr;
                    if (nitr!=nlitr->end() && !nitr->isInteger()) {
                        sublst = new NestedIterator((vector<NestedInteger>&)nitr->getList());
                        if (!sublst->hasNext()) {
                            delete sublst;
                            ++nitr;
                            continue;
                        }
                    }
                    break;
                }
            }
        }
        return res;
    }
    bool hasNext() {
        return (nitr != nlitr->end());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    return 0;
}
