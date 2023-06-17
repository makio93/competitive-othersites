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

const double PI = acos(-1);

int main() {
	int r, k;
	cin >> r >> k;
	if (k%2 == 1) {
		vector<double> res;
		double tar = ((double)r * r * PI / 2.0) / (k/2+1);
		res.push_back(0.0);
		rep3(i, 1, k/2+1) {
			double li = 0.0, ri = r;
			while (ri-li > 1e-5) {
				double ci = (li + ri) / 2.0, th = asin(ci/r);
				double area = ((double)r * r * PI / 2.0) * (th / PI) * 2.0 + r * cos(th) * 2.0 * ci / 2.0;
				if (area < tar*i) li = ci;
				else ri = ci;
			}
			res.push_back(ri);
			res.push_back(-ri);
		}
		sort(all(res));
		rep(i, k) cout << fixed << setprecision(10) << res[i] << endl;
	}
	else {
		vector<double> res;
		double tar = ((double)r * r * PI / 2.0) / (k+1);
		for (int i=1; i<k; i+=2) {
			double li = 0.0, ri = r;
			while (ri-li > 1e-5) {
				double ci = (li + ri) / 2.0, th = asin(ci/r);
				double area = ((double)r * r * PI / 2.0) * (th / PI) * 2.0 + r * cos(th) * 2.0 * ci / 2.0;
				if (area < tar*i) li = ci;
				else ri = ci;
			}
			res.push_back(ri);
			res.push_back(-ri);
		}
		sort(all(res));
		rep(i, k) cout << fixed << setprecision(10) << res[i] << endl;
	}
	return 0;
}
