// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct SegmentTree {
	int n;
	vector<int> dat;
	SegmentTree() { init(1); }
	SegmentTree(int n_) { init(n_); }
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat = vector<int>(2*n-1, 0);
	}
	void update(int k, int a) {
		k += n-1;
		dat[k] = a;
		while (k > 0) {
			k = (k-1) / 2;
			dat[k] = max(dat[k*2+1], dat[k*2+2]);
		}
	}
	int query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) { r = n; k = 0; l = 0; }
		if (r<=a || b<=l) return 0;
		if (a<=l && r<=b) return dat[k];
		else {
			int vl = query(a, b, k*2+1, l, (l+r)/2);
			int vr = query(a, b, k*2+2, (l+r)/2, r);
			return max(vl, vr);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	SegmentTree st(m+1);
	rep(i, m) st.update(i, a[i]);
	int q;
	cin >> q;
	rep(i, q) {
		int xs, ys, xf, yf, ki;
		cin >> xs >> ys >> xf >> yf >> ki;
		--xs; --ys; --xf; --yf;
		if (abs(ys-yf)%ki!=0 || abs(xs-xf)%ki!=0) {
			cout << "NO" << endl;
			continue;
		}
		if (ys > yf) {
			swap(xs, xf);
			swap(ys, yf);
		}
		int mx = st.query(ys, yf+1);
		if (mx > xs) {
			int sub = mx - xs, asub = (sub+ki-1) / ki * ki;
			if (xs+asub >= n) {
				cout << "NO" << endl;
				continue;
			}
		}
		cout << "YES" << endl;
	}
	return 0;
}
