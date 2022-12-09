// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
using mint = modint998244353;
template<typename T>
struct Matrix {
	int h, w;
	vector<vector<T>> d;
	Matrix() {}
	Matrix(int h, int w, T val=0) : h(h), w(w), d(h, vector<T>(w, val)) {}
	Matrix& unit() {
		assert(h == w);
		rep(i, h) d[i][i] = 1;
		return *this;
	}
	const vector<T>& operator[](int i) const { return d[i]; }
	vector<T>& operator[](int i) { return d[i]; }
	Matrix operator*(const Matrix& a) const {
		assert(w == a.h);
		Matrix r(h, a.w);
		rep(i, h) rep(k, w) rep(j, a.w) {
			r[i][j] += d[i][k] * a[k][j];
		}
		return r;
	}
	Matrix pow(long long t) const {
		assert(h == w);
		if (!t) return Matrix(h, h).unit();
		if (t == 1) return *this;
		Matrix r = pow(t>>1);
		r = r * r;
		if (t&1) r = r * (*this);
		return r;
	}
};

int main() {
	ll n;
	cin >> n;
	int nl = 0;
	ll tn = 1;
	while (tn < n) {
		tn *= 2;
		++nl;
	}
	Matrix<mint> mat(5, 5);
	mat.d = { 
		{ 1, 0, 1, 0, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 1, 0 }
	};
	mat = mat.pow(n-1);
	vector<mint> a = { 0, 1, 0, 0, 1 }, rval(5);
	rep(i, 5) rep(j, 5) rval[i] += mat.d[i][j] * a[j];
	mint res = rval[0] + rval[2];
	cout << res.val() << endl;
	return 0;
}
