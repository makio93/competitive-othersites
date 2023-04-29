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
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n*(n+1)/2%n == 0) {
			cout << -1 << endl;
			continue;
		}
		vector<int> p(n);
		set<int> vlst;
		rep3(i, 1, n+1) vlst.insert(i);
		auto check = [&](int si) -> bool {
			auto leaved = vlst;
			p[0] = si;
			leaved.erase(si);
			rep3(i, 1, n) {
				int val = -1;
				for (const int& vi : leaved) {
					bool ok = true;
					int sum = vi;
					repr(j, i) {
						sum += p[j];
						if (sum%(i-j+1) == 0) {
							ok = false;
							break;
						}
					}
					if (!ok) continue;
					val = vi;
					break;
				}
				if (val == -1) return false;
				p[i] = val;
				leaved.erase(val);
			}
			return true;
		};
		bool res = false;
		rep3(i, 1, n+1) {
			if (check(i)) {
				res = true;
				break;
			}
		}
		if (res) {
			rep(i, n) cout << p[i] << (i<n-1?' ':'\n');
		}
		else cout << -1 << endl;
	}
	return 0;
}
