// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    stack<NestedInteger*> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        listPush(nestedList);
    }
    void listPush(vector<NestedInteger> &nestedList) {
        for (auto itr=nestedList.rbegin(); itr!=nestedList.rend(); ++itr) st.push(&*itr);
    }
    int next() {
        hasNext();
        int res = st.top()->getInteger();
        st.pop();
        return res;
    }
    bool hasNext() {
        while (!st.empty() && !st.top()->isInteger()) {
            auto vi = st.top(); st.pop();
            listPush(const_cast<vector<NestedInteger>&>(vi->getList()));
        }
        return !st.empty();
    }
};
