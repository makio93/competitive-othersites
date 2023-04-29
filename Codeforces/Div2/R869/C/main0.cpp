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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<pair<int, int>> aids;
	aids.emplace_back(0, 1);
	rep3(i, 1, n) {
		if (a[i] > a[i-1]) aids.emplace_back(i, 1);
		else if (aids.back().second == 1) aids.emplace_back(i, -1);
	}
	vector<int> bids;
	for (const auto& pi : aids) bids.push_back(pi.first);
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li; --ri;
		int lid = upper_bound(all(bids), li) - bids.begin() - 1, rid = upper_bound(all(bids), ri) - bids.begin(), add = 0;
		if (aids[lid].second == -1) {
			if (lid+1 == rid) {
				if (min(n, ri+1)-li >= 2) ++add;
			}
			else {
				if (bids[lid+1]-li >= 2) ++add;
			}
		}
		cout << (rid-lid+add) << endl;
	}
	return 0;
}
