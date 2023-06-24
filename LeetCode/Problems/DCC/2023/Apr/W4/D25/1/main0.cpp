// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    int limit;
    set<int> ast;
public:
    SmallestInfiniteSet() { limit = 0; }
    int popSmallest() {
        if (ast.empty()) return ++limit;
        else {
            int tval = *ast.begin();
            ast.erase(ast.begin());
            return tval;
        }
    }
    void addBack(int num) {
        if (num > limit || ast.find(num) != ast.end()) return;
        ast.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
