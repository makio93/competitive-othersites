#include <bits/stdc++.h>
using namespace std;

// 本番WA

class LockingTree {
    int n;
    vector<int> par;
    map<int, int> locks;
    map<pair<int, int>, bool> memo;
    bool isanc(int v, int t) {
        if (memo.find({v, t}) != memo.end()) return memo[{v, t}];
        if (v == -1) return (memo[{v, t}] = false);
        if (v == t) return (memo[{v, t}] = memo[{t, v}] = true);
        bool res = isanc(par[v], t);
        if (res) memo[{t, v}] = (!res);
        return (memo[{v, t}] = res);
    }
public:
    LockingTree(vector<int>& parent) {
        n = parent.size();
        par = parent;
        locks = map<int, int>();
        memo = map<pair<int, int>, bool>();
    }
    bool lock(int num, int user) {
        if (locks.find(num) == locks.end()) {
            locks[num] = user;
            return true;
        }
        else return false;
    }
    bool unlock(int num, int user) {
        if (locks.find(num)!=locks.end() && locks[num]==user) {
            locks.erase(num);
            return true;
        }
        else return false;
    }
    bool upgrade(int num, int user) {
        if (locks.find(num) != locks.end()) return false;
        for (auto p : locks) if (isanc(num, p.first)) return false;
        bool ok = false;
        auto itr = locks.begin();
        while (itr != locks.end()) {
            if (isanc(itr->first, num)) {
                ok = true;
                itr = locks.erase(itr);
            }
            else ++itr;
        }
        if (!ok) return false;
        locks[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
