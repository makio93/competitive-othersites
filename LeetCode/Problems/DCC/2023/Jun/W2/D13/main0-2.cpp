// 自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
const int MX = (int)(1e5+5);
unsigned xorshift(){
    static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned t = x ^ (x<<11);
    x = y; y = z; z = w; w ^= t ^ (t>>8) ^ (w>>19);
    return w;
}
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<unsigned> hvals(MX);
        for (int i=0; i<MX; ++i) hvals[i] = xorshift();
        vector<unsigned> rvals(n), cvals(n);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) rvals[i] = (unsigned)(((ll)rvals[i] * MX + hvals[grid[i][j]]) % mod);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cvals[i] = (unsigned)(((ll)cvals[i] * MX + hvals[grid[j][i]]) % mod);
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (rvals[i] == cvals[j]) ++res;
        return res;
    }
};
