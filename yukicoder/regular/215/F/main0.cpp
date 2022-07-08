// 自力AC,ヒント有

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;

struct Matrix {
	int sz;
	vector<vector<ll>> x;
	Matrix(int sz=0) : sz(sz), x(sz, vector<ll>(sz)) {}
};

Matrix multiply(Matrix A, Matrix B) {
	Matrix C(A.sz);
	rep(i, A.sz) rep(j, B.sz) {
		rep(k, C.sz) C.x[i][j] = (C.x[i][j] + A.x[i][k] * B.x[k][j]) % mod;
	}
	return C;
}

Matrix matpow(Matrix A, ll t) {
	vector<Matrix> E(64, Matrix(A.sz));
	E[0] = A;
	rep(i, 63) E[i+1] = multiply(E[i], E[i]);
	Matrix res(A.sz);
	rep(i, res.sz) res.x[i][i] = 1;
	repr(i, 63) if (t & (1LL<<i)) res = multiply(res, E[i]);
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	Matrix mat(k*k*k);
	rep(i, k*k*k) {
		int v1 = i%k, v2 = i/k%k, v3 = i/k/k%k;
		int nv1 = (v1+1) % k, nv2 = (v2+v1) % k, nv3 = (v3+v2) % k;
		mat.x[nv1+v2*k+v3*k*k][i]++;
		mat.x[v1+nv2*k+v3*k*k][i]++;
		mat.x[v1+v2*k+nv3*k*k][i]++;
	}
	auto amat = matpow(mat, n);
	ll res = 0;
	rep(i, k*k*k) if (i/k/k == 0) res = (res + amat.x[i][0]) % mod;
	cout << res << endl;
	return 0;
}
