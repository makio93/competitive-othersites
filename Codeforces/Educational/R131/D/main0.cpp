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
		vector<int> b(n);
		rep(i, n) cin >> b[i];
		vector<pair<pair<int, int>, int>> plst;
		rep(i, n) {
			int li = (i+1) / (b[i]+1) + 1, ri = (b[i]==0) ? n : (i+1) / b[i];
			plst.emplace_back(make_pair(li, -ri), i);
		}
		sort(plst.rbegin(), plst.rend());
		vector<int> a(n);
		set<int> nums;
		rep3(i, 1, n+1) nums.insert(i);
		rep(i, n) {
			int li = plst[i].first.first, ri = -plst[i].first.second, id = plst[i].second;
			auto itr = prev(nums.upper_bound(ri));
			a[id] = *itr;
			nums.erase(*itr);
		}
		rep(i, n) cout << a[i] << (i<n-1?' ':'\n');
	}
	return 0;
}
