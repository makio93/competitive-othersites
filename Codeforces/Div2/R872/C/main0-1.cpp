// 本番WA1

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
		int n, m;
		cin >> n >> m;
		vector<int> x(n);
		rep(i, n) cin >> x[i];
		set<int> s;
		rep(i, n) {
			if (x[i] == -1) {
				if (s.empty()) s.insert(m);
				else if ((*s.begin()) > 1) s.insert((*s.begin())-1);
			}
			else if (x[i] == -2) {
				if (s.empty()) s.insert(1);
				else if ((*s.rbegin()) < m) s.insert((*s.rbegin())+1);
			}
			else {
				if (s.find(x[i]) == s.end()) s.insert(x[i]);
			}
		}
		cout << (int)(s.size()) << endl;
	}
	return 0;
}
