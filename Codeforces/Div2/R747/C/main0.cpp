#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		char c;
		cin >> n >> c;
		string s;
		cin >> s;
		if (s == string(n, c)) {
			printf("0\n");
			continue;
		}
		vector<int> res;
		bool same = false;
		rep3r(i, n/2, n) {
			if (s[i] == c) {
				res.push_back(i+1);
				same = true;
				break;
			}
		}
		if (!same) {
			res.push_back(n);
			res.push_back(n-1);
		}
		int len = res.size();
		printf("%d\n", len);
		rep(i, len) printf("%d%c", res[i], (i<len-1?' ':'\n'));
	}
	return 0;
}
