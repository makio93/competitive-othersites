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
		vector<int> cnt(2);
		rep(i, n) {
			if (a[i]%10==0 || a[i]%10==5) cnt[0]++;
			else cnt[1]++;
		}
		if (cnt[0]>0 && cnt[1]>0) {
			cout << "No" << endl;
			continue;
		}
		if (cnt[0] > 0) {
			rep(i, n) if (a[i]%10 == 5) a[i] += 5;
			bool ok = true;
			rep3(i, 1, n) if (a[i] != a[0]) {
				ok = false;
				break;
			}
			if (ok) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else {
			rep(i, n) {
				int tval = a[i]%10;
				while (tval != 2) {
					a[i] += tval;
					tval = a[i]%10;
				}
			}
			bool ok = true;
			rep3(i, 1, n) if (a[i]%20 != a[0]%20) {
				ok = false;
				break;
			}
			if (ok) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
