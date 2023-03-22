// 学習1回目,解説AC1-2

#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.emplace(nestedList.begin(), nestedList.end());
    }
    int next() {
        hasNext();
        return (st.top().first++)->getInteger();
    }
    bool hasNext() {
        while (!st.empty()) {
            if (st.top().first == st.top().second) st.pop();
            else if (st.top().first->isInteger()) return true;
            else {
                auto itr = st.top().first++;
                st.emplace(itr->getList().begin(), itr->getList().end());
            }
        }
        return false;
    }
};
