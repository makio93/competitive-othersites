// 自力AC

#include <bits/stdc++.h>
using namespace std;

class LockingTree {
    int n;
    vector<int> par, ccnt, uids;
    vector<vector<int>> children;
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        par = parent;
        children.assign(n, vector<int>());
        for (int i=0; i<n; ++i) if (par[i] != -1) children[par[i]].push_back(i);
        ccnt.assign(n, 0);
        uids.assign(n, 0);
    }
    void add(int num, int val) {
        while (num != -1) {
            ccnt[num] += val;
            num = par[num];
        }
    }
    bool check(int num) {
        num = par[num];
        while (num != -1) {
            if (uids[num] != 0) return false;
            num = par[num];
        }
        return true;
    }
    void sweep(int num) {
        add(num, -ccnt[num]);
        queue<int> que;
        uids[num] = ccnt[num] = 0;
        que.push(num);
        while (!que.empty()) {
            int qi = que.size();
            for (int i=0; i<qi; ++i) {
                int vi = que.front(); que.pop();
                for (const int& ti : children[vi]) {
                    uids[ti] = ccnt[ti] = 0;
                    que.push(ti);
                }
            }
        }
    }
    bool lock(int num, int user) {
        if (uids[num] != 0) return false;
        add(num, 1);
        uids[num] = user;
        return true;
    }
    bool unlock(int num, int user) {
        if (uids[num] != user) return false;
        add(num, -1);
        uids[num] = 0;
        return true;
    }
    bool upgrade(int num, int user) {
        if (uids[num]!=0 || ccnt[num]==0 || !check(num)) return false;
        sweep(num);
        return lock(num, user);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */