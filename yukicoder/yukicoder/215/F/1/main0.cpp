// 学習1回目,自力AC

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
    int n, k;
    cin >> n >> k;
    Matrix<mint> r(k*k*k, k*k*k);
    rep(i1, k) rep(i2, k) rep(i3, k) {
        int j1 = (i1 + 1) % k, j2 = i2, j3 = i3;
        r[i1*k*k+i2*k+i3][j1*k*k+j2*k+j3] += 1;
        j1 = i1, j2 = (i2 + i1) % k, j3 = i3;
        r[i1*k*k+i2*k+i3][j1*k*k+j2*k+j3] += 1;
        j1 = i1, j2 = i2, j3 = (i3 + i2) % k;
        r[i1*k*k+i2*k+i3][j1*k*k+j2*k+j3] += 1;
    }
    r = r.pow(n);
    mint res = 0;
    for (int i=0; i<k*k*k; i+=k) res += r[i][0];
    cout << res.val() << endl;
    return 0;
}
