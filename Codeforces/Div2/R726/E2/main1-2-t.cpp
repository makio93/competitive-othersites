#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC,(Zアルゴリズムを用いた実装,解説実装を真似る,AC)

vector<int> z_calc(string &s) {
    int n = s.size(), L = -1, R = -1;
    vector<int> z(n);
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i <= R)
            z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if(i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

void printstr(string s, int k) {
    int len = 0, slen = s.length();
    string res;
    while (len < k) {
        res += s;
        len += slen;
    }
    cout << res.substr(0, k) << endl;
    exit(0);
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> z = z_calc(s);
    int rid = 1;
    rep3(i, 1, n) {
        if (s[i] > s[i%rid]) printstr(s.substr(0, rid), k);
        if (s[i] < s[i%rid]) {
            rid = i + 1;
            continue;
        }
        int aid = i - rid;
        if (aid+1 == rid) {
            rid = i + 1;
            continue;
        }
        if (z[aid+1] <= rid-aid-2) {
            if (s[z[aid+1]] < s[aid+1+z[aid+1]]) rid = i+1;
            continue;
        }
        int bid = rid - aid;
        if (z[bid-1] <= rid-bid) {
            if (s[bid-1+z[bid-1]] < s[z[bid-1]]) rid = i+1;
            continue;
        }
        rid = i + 1;
    }
    printstr(s.substr(0, rid), k);
    return 0;
}
