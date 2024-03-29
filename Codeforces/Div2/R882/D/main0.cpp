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
	int n;
	vector<T> node, lazy;
public:
	LazySegmentTree(int n_) : LazySegmentTree(vector<T>(n_)) {}
	LazySegmentTree(vector<T> v) {
		int n_ = v.size();
		n = 1;
		while (n < n_) n *= 2;
		node.resize(n*2-1, 0);
		lazy.resize(n*2-1, 0);
		for (int i=0; i<n_; ++i) node[n+i-1] = v[i];
		for (int i=n-2; i>=0; --i) node[i] = node[i*2+1] + node[i*2+2];
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			if (r-l > 1) {
				lazy[k*2+1] += lazy[k] / 2;
				lazy[k*2+2] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}
	void add(int a, int b, T x, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (b<=l || r<=a) return;
		if (a<=l && r<=b) {
			lazy[k] += x * (r-l);
			eval(k, l, r);
		}
		else {
			add(a, b, x, k*2+1, l, (l+r)/2);
			add(a, b, x, k*2+2, (l+r)/2, r);
			node[k] = node[k*2+1] + node[k*2+2];
		}
	}
	T getSum(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (b<=l || r<=a) return 0;
		if (a<=l && r<=b) return node[k];
		T vl = getSum(a, b, k*2+1, l, (l+r)/2);
		T vr = getSum(a, b, k*2+2, (l+r)/2, r);
		return vl + vr;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	string s;
	cin >> n >> m >> q >> s;
	vector<int> l(m), r(m);
	vector<int> mul(n+1);
	rep(i, m) {
		cin >> l[i] >> r[i];
		--l[i];
		mul[l[i]]++;
		mul[r[i]]--;
	}
	rep(i, n) mul[i+1] += mul[i];
	ll ocnt = 0;
	rep(i, n) if (s[i] == '1') ocnt += mul[i];
	vector<ll> ilst;
	ilst.push_back(0);
	ll tmp = 0;
	rep(i, m) {
		tmp += r[i] - l[i];
		ilst.push_back(tmp);
	}
	LazySegmentTree<ll> zmul(n+1);
	vector<int> zsums(n+1);
	rep(i, n) zsums[i+1] = zsums[i] + (s[i] == '0' ? 1 : 0);
	ll zcnt = 0;
	function<void(ll, ll)> zadd = [&](ll lo, ll ro) {
		int l1 = lower_bound(all(ilst), lo) - ilst.begin() - 1, r1 = lower_bound(all(ilst), ro) - ilst.begin() - 1;
		int l2 = lo - ilst[l1], r2 = ro - ilst[r1];
		if (l1 == r1) {
			zcnt += zsums[l[l1]+r2+1] - zsums[l[l1]+l2];
			zmul.add(l[l1]+l2, l[l1]+r2+1, 1);
		}
		else {
			zcnt += zsums[r[l1]] - zsums[l[l1]+l2];
			zmul.add(l[l1]+l2, r[l1], 1);
			rep3(i1, l1+1, r1) {
				zcnt += zsums[r[i1]] - zsums[l[i1]];
				zmul.add(l[i1], r[i1], 1);
			}
			zcnt += zsums[l[r1]+r2+1] - zsums[l[r1]];
			zmul.add(l[r1], l[r1]+r2+1, 1);
		}
	};
	function<void(ll, ll)> zrem = [&](ll lo, ll ro) {
		int l1 = lower_bound(all(ilst), lo) - ilst.begin() - 1, r1 = lower_bound(all(ilst), ro) - ilst.begin() - 1;
		int l2 = lo - ilst[l1], r2 = ro - ilst[r1];
		if (l1 == r1) {
			zcnt -= zsums[l[l1]+r2+1] - zsums[l[l1]+l2];
			zmul.add(l[l1]+l2, l[l1]+r2+1, -1);
		}
		else {
			zcnt -= zsums[r[l1]] - zsums[l[l1]+l2];
			zmul.add(l[l1]+l2, r[l1], -1);
			rep3(i1, l1+1, r1) {
				zcnt -= zsums[r[i1]] - zsums[l[i1]];
				zmul.add(l[i1], r[i1], -1);
			}
			zcnt -= zsums[l[r1]+r2+1] - zsums[l[r1]];
			zmul.add(l[r1], l[r1]+r2+1, -1);
		}
	};
	zadd(0, ocnt);
	rep(i, q) {
		int xi;
		cin >> xi;
		--xi;
		if (s[xi] == '0') {
			ll tmp = zmul.getSum(xi, xi+1);
			zcnt -= tmp;
			s[xi] = '1';
			zadd(ocnt, ocnt+tmp);
			ocnt += tmp;
		}
		else {
			ll tmp = zmul.getSum(xi, xi+1);
			s[xi] = '0';
			zrem(ocnt-tmp, ocnt+1);
			zcnt += tmp;
			ocnt -= tmp;
		}
		cout << zcnt << endl;
	}
	return 0;
}
