// 本番WA

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
		vector<int> a(m);
		rep(i, m) {
			cin >> a[i];
			a[i]--;
		}
		vector<int> acnt(n);
		rep(i, m) acnt[a[i]]++;
		int res = 0;
		priority_queue<pair<int, int>> pq;
		rep(i, n) if (acnt[i] > 0) pq.emplace(acnt[i], i);
		while (!pq.empty()) {
			int add = 0;
			priority_queue<pair<int, int>> npq;
			unordered_set<int> wst;
			rep(i, n) wst.insert(i);
			while (!pq.empty()) {
				auto pi = pq.top(); pq.pop();
				int sub = min(2, pi.first), ci = pi.first, wi = pi.second;
				add = max(add, sub);
				ci -= sub;
				wst.erase(wi);
				if (ci > 0) npq.emplace(ci, wi);
			}
			while (!npq.empty() && !wst.empty()) {
				auto pi = npq.top(); npq.pop();
				int sub = min(1, pi.first), ci = pi.first, wi = pi.second;
				add = max(add, 2);
				ci -= sub;
				wst.erase(wst.begin());
				if (ci > 0) pq.emplace(ci, wi);
			}
			res += add;
		}
		cout << res << endl;
	}
	return 0;
}
