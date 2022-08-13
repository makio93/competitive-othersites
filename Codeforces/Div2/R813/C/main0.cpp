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
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		unordered_set<int> svals;
		int id1 = -1;
		repr(i, n-1) {
			if (id1 == -1) {
				if (a[i] > a[i+1]) {
					id1 = i;
					svals.insert(a[i]);
				}
			}
			else svals.insert(a[i]);
		}
		if (id1 == -1) {
			cout << 0 << endl;
			continue;
		}
		bool er = false;
		rep3r(i, id1+1, n) {
			if (!er) {
				if (svals.find(a[i]) != svals.end()) er = true;
			}
			else svals.insert(a[i]);
		}
		cout << (int)(svals.size()) << endl;
	}
	return 0;
}
