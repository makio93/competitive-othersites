// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

template<typename T>
class LazySegmentTree {
	T INF_ST;
	int n;
	vector<T> node, lazy;
	vector<int> vcnt;
public:
	LazySegmentTree(int n_, T INF_ST_=numeric_limits<T>::max()) : LazySegmentTree(vector<T>(n_, INF_ST_), INF_ST_) {}
	LazySegmentTree(vector<T> v, T INF_ST_=numeric_limits<T>::max()) : INF_ST(INF_ST_) {
		int n_ = v.size();
		n = 1;
		while (n < n_) n *= 2;
		node.resize(n*2-1, INF_ST);
		lazy.resize(n*2-1, INF_ST);
		for (int i=0; i<n_; ++i) node[n+i-1] = v[i];
		for (int i=n-2; i>=0; --i) node[i] = min(node[i*2+1], node[i*2+2]);
		vcnt.resize(n*2-1, 0);
		vcnt[n-1] = 1;
		for (int i=1; i<n_; ++i) vcnt[n+i-1] = (v[i-1] != v[i]) ? 1 : 0;
		for (int i=n-2; i>=0; --i) vcnt[i] = vcnt[i*2+1] + vcnt[i*2+2];
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != INF_ST) {
			node[k] = min(node[k], lazy[k]);
			if (r-l > 1) {
				lazy[k*2+1] = lazy[k*2+2] = lazy[k];
			}
			else {
				if (k==n-1 || node[k-1]!=node[k]) vcnt[k] = 1;
				else vcnt[k] = 0;
			}
			lazy[k] = INF_ST;
		}
	}
	void update(int a, int b, T x, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (b<=l || r<=a) return;
		if (a<=l && r<=b) {
			lazy[k] = x;
			eval(k, l, r);
		}
		else {
			update(a, b, x, k*2+1, l, (l+r)/2);
			update(a, b, x, k*2+2, (l+r)/2, r);
			node[k] = min(node[k*2+1], node[k*2+2]);
			vcnt[k] = vcnt[k*2+1] + vcnt[k*2+2];
		}
	}
	int find(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (b<=l || r<=a) return 0;
		if (a<=l && r<=b) return vcnt[k];
		int vl = find(a, b, k*2+1, l, (l+r)/2);
		int vr = find(a, b, k*2+2, (l+r)/2, r);
		return vl + vr;
	}
};

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		rep(i, n-1) a[i+1] = min(a[i+1], a[i]);
		LazySegmentTree<int> lst(a);
		rep(i, m) {
			int ki, di;
			cin >> ki >> di;
			--ki;
			lst.update(ki, n, di);
			cout << lst.find(0, n) << ' ';
		}
		cout << endl;
	}
	return 0;
}
