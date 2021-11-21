#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    bool mirror(ll val, int k) {
        string str;
        while (val > 0) {
            str.push_back((char)(val%k+'0'));
            val /= k;
        }
        if (str.front() == '0') return false;
        for (int l=0; l<(int)(str.length())-l-1; ++l) if (str[l] != str[(int)(str.length())-l-1]) return false;
        return true;
    }
    void dfs(vector<ll>& lst, string& str, int k, int n, int d) {
        if (lst.size() >= n) return;
        if ((int)(str.length()) >= (d+1)/2) {
            string tstr = str, rstr = str;
            reverse(rstr.begin(), rstr.end());
            if (d%2 == 0) tstr += rstr;
            else if (rstr.length() > 1) tstr += rstr.substr(1);
            if (mirror(stoll(tstr), k)) lst.push_back(stoll(tstr));
        }
        else {
            for (char c='0'; c<=(char)('9'); ++c) {
                if (lst.size() >= n) return;
                if (str.empty() && c=='0') continue;
                str.push_back(c);
                dfs(lst, str, k, n, d);
                str.pop_back();
            }
        }
    }
    ll kMirror(int k, int n) {
        vector<ll> lst;
        int d = 0;
        while (lst.size() < n) {
            ++d;
            string str;
            dfs(lst, str, k, n, d);
        }
        ll res = 0;
        for (ll val : lst) res += val;
        return res;
    }
};
