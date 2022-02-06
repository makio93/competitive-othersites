#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Bitset {
    int len, cnt;
    bool rev;
    vector<bool> bset;
public:
    Bitset(int size) {
        len = size;
        cnt = 0;
        rev = false;
        bset = vector<bool>(len);
    }
    void fix(int idx) {
        if (!rev) {
            if (!bset[idx]) {
                bset[idx] = true;
                ++cnt;
            }
        }
        else {
            if (bset[idx]) {
                bset[idx] = false;
                --cnt;
            }
        }
    }
    void unfix(int idx) {
        if (!rev) {
            if (bset[idx]) {
                bset[idx] = false;
                --cnt;
            }
        }
        else {
            if (!bset[idx]) {
                bset[idx] = true;
                ++cnt;
            }
        }
    }
    void flip() {
        rev = !rev;
    }
    bool all() {
        if (!rev) return (cnt == len);
        else return (cnt == 0);
    }
    bool one() {
        if (!rev) return (cnt != 0);
        else return (cnt != len);
    }
    int count() {
        if (!rev) return cnt;
        else return (len - cnt);
    }
    string toString() {
        string res;
        for (int i=0; i<len; ++i) {
            if (!rev) {
                if (bset[i]) res += '1';
                else res += '0';
            }
            else {
                if (bset[i]) res += '0';
                else res += '1';
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
