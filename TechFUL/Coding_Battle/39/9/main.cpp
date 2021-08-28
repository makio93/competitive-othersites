#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class SuffixArray {
public:
    int n;
    vector<int> sa, rank, lcp;
    SuffixArray(string s) {
        n = s.length();
        sa = vector<int>(n+1);
        rank = vector<int>(n+1, -1);
        for (int i=0; i<=n; ++i) sa[i] = i;
        for (int i=0; i<n; ++i) rank[i] = (int)(s[i]);
        vector<int> tmp(n+1);
        for (int k=1; k<=n; k*=2) {
            function<bool(int,int)> compare_sa = [&](int i, int j) {
                if (rank[i] != rank[j]) return (rank[i] < rank[j]);
                else {
                    int ri = i + k <= n ? rank[i+k] : -1;
                    int rj = j + k <= n ? rank[j+k] : -1;
                    return (ri < rj);
                }
            };
            sort(sa.begin(), sa.end(), compare_sa);
            tmp[sa[0]] = 0;
            for (int i=1; i<=n; ++i) tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
            for (int i=0; i<=n; ++i) rank[i] = tmp[i];
        }
        lcp = vector<int>(n+1);
        //for (int i=0; i<=n; ++i) rank[sa[i]] = i;
        int h = 0;
        lcp[0] = 0;
        for (int i=0; i<n; ++i) {
            int j = sa[rank[i]-1];
            if (h > 0) --h;
            while (j+h<n && i+h<n) {
                if (s[j+h] != s[i+h]) break;
                ++h;
            }
            lcp[rank[i]-1] = h;
        }
    }
};

struct SegmentTree {
    int n;
    vector<int> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(1e9));
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return (int)(1e9);
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    SuffixArray sa(s);
    SegmentTree st(n+1);
    for (int i=0; i<=n; ++i) st.update(i, sa.lcp[i]);
    cout << "inf" << endl;
    for (int i=1; i<n; ++i) {
        pair<int, int> sid = { sa.rank[0], sa.rank[i] };
        if (sid.first > sid.second) swap(sid.first, sid.second);
        int res = st.query(sid.first, sid.second);
        if (res >= (n-i)) {
            pair<int, int> sid2 = { sa.rank[n-i], sa.rank[0] };
            if (sid2.first > sid2.second) swap(sid2.first, sid2.second);
            int val2 = min(i, st.query(sid2.first, sid2.second));
            res += val2;
        }
        if (res < n) cout << res << endl;
        else cout << "inf" << endl;
    }
    return 0;
}
