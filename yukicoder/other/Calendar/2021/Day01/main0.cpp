#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,作成途中

int main() {
	int t0, r;
	cin >> t0 >> r;
	vector<int> s;
	multiset<int> sval;
	int cval = -1;
	rep(i0, t0) {
		int n;
		cin >> n;
		rep(i, n) {
			int si;
			cin >> si;
			s.push_back(si);
			if (cval == -1) cval = si;
			else {

			}
		}

	}
	return 0;
}
