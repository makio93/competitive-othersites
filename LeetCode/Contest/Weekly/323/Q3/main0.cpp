// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Allocator {
    int nlen;
    map<int, int> mlst;
    map<int, vector<int>> mids;
public:
    Allocator(int n) {
        nlen = n;
        mlst[-1] = mlst[nlen] = 1;
    }
    int allocate(int size, int mID) {
        for (auto itr=mlst.begin(); itr->first<nlen; ++itr) {
            int li = itr->first + itr->second, ri = next(itr)->first;
            if (ri-li >= size) {
                mlst[li] = size;
                mids[mID].push_back(li);
                return li;
            }
        }
        return -1;
    }
    int free(int mID) {
        int rval = 0;
        if (mids.find(mID) != mids.end()) {
            for (const int& li : mids[mID]) {
                rval += mlst[li];
                mlst.erase(li);
            }
            mids.erase(mID);
        }
        return rval;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
