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
		vector<int> aid, zid;
		rep(i, n) {
			if (a[i] != 0) aid.push_back(i);
			else zid.push_back(i);
		}
		int alen = aid.size();
		if (alen%2 == 1) {
			cout << -1 << endl;
			continue;
		}
		vector<pair<int, int>> res;
		int li = -1, sum = 0;
		vector<bool> used(n);
		rep(i, alen) {
			if (li == -1) {
				used[aid[i]] = true;
				res.emplace_back(aid[i]+1, -1);
				li = i;
				sum += a[aid[i]];
			}
			else {
				if ((i-li+1)%2 == 0) {
					int add = a[aid[i]] * -1;
					if (sum+add == 0) {
						sum += add;
						if (aid[i-1]+1 < aid[i]) {
							res.back().second = aid[i-1]+1;
							used[aid[i]-1] = used[aid[i]] = true;
							res.emplace_back(aid[i], aid[i]+1);
						}
						else {
							used[aid[i]] = true;
							res.back().second = aid[i] + 1;
						}
						li = -1;
					}
					else {
						sum += a[aid[i]];
						res.back().second = aid[i-1] + 1;
						li = i;
						used[aid[i]] = true;
						res.emplace_back(aid[i]+1, -1);
					}
				}
				else {
					sum += a[aid[i]];
					used[aid[i]] = true;
				}
			}
			if (i==alen-1 && res.back().second==-1) res.back().second = res.back().first;
		}
		rep(i, n) if (!used[i]) res.emplace_back(i+1, i+1);
		sort(all(res));
		int klen = res.size();
		cout << klen << endl;
		rep(i, klen) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
