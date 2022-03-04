// 自力2,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<ll> add(1, 1);
        vector<double> vals(1, 0.0);
        ll two = 1;
        for (int i=0; i<100; ++i) {
            if ((ll)poured > two) {
                for (int j=0; j<i+1; ++j) vals[j] += (double)add[j] / two;
                poured -= two;
            }
            else if (poured > 0) {
                for (int j=0; j<i+1; ++j) vals[j] += (double)add[j] / poured;
                poured = 0;
            }
            if (i == query_row) return min(1.0, vals[query_glass]);
            vector<ll> nadd(i+2);
            vector<double> nvals(i+2);
            for (int j=0; j<i+1; ++j) {
                nadd[j] += add[j]; nadd[j+1] += add[j];
                if (vals[j] > 1.0) { nvals[j] += (vals[j] - 1.0) / 2.0; nvals[j+1] += (vals[j] - 1.0) / 2.0; }
            }
            swap(add, nadd); swap(vals, nvals);
            if (poured > 0) two *= 2;
        }
        return 1.0;
    }
};
