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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> res;
		res.push_back(1);
		int lval = (s[0] == '0') ? 0 : 1, rval = (s[0] == '0') ? 0 : 1;
		rep3(i, 1, n-1) {
			if (s[i] == '0') {
				res.push_back(rval+1);
				lval = 0;
			}
			else {
				res.push_back((i+1)-lval);
				++lval;
				rval = i + 1;
			}
		}
		rep(i, n-1) cout << res[i] << (i<n-2?' ':'\n');
	}
	return 0;
}
