// 自力AC

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
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0) : n(n), d(n+1) {}
	void add(int i, T x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i-=i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	BIT<int> a(n);
	rep(i, q) {
		int qi, xi, yi;
		cin >> qi >> xi >> yi;
		--xi;
		if (qi == 0) a.add(xi, yi);
		else cout << a.sum(xi, yi) << endl;
	}
	return 0;
}
