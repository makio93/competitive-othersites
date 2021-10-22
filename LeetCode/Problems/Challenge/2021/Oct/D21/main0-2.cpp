#include <bits/stdc++.h>
using namespace std;

// 自力AC2

using ll = long long;
class RandomizedSet {
    int sval, mod;
    ll forb, add;
    vector<pair<ll, int>> vals;
    vector<ll> vlst;
public:
    RandomizedSet() {
        srand(time(NULL));
        sval = 0; mod = (int)(2e5)+5;
        forb = (1LL<<31); add = (1LL<<30);
        vals = vector<pair<ll, int>>(mod, { forb, 0 });
        vlst = vector<ll>();
    }
    bool insert(int val) {
        val += add;
        int pval = val % mod;
        while (vals[pval].first!=forb && vals[pval].first!=(ll)val) pval = (pval + 1) % mod;
        if (vals[pval].first == forb) {
            vals[pval] = { (ll)val, sval };
            vlst.push_back((ll)val);
            ++sval;
            return true;
        }
        else return false;
    }
    bool remove(int val) {
        val += add;
        int pval = val % mod;
        while (vals[pval].first!=forb && vals[pval].first!=(ll)val) pval = (pval + 1) % mod;
        if (vals[pval].first == (ll)val) {
            int vid = vals[pval].second;
            int pval2 = vlst.back() % mod;
            while (vals[pval2].first != vlst.back()) pval2 = (pval2 + 1) % mod;
            swap(vlst.back(), vlst[vals[pval].second]);
            vals[pval2].second = vals[pval].second;
            vals[pval].first = forb;
            vlst.pop_back();
            --sval;
            return true;
        }
        else return false;
    }
    int getRandom() { return (int)(vlst[(int)(rand())%sval] - add); }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
