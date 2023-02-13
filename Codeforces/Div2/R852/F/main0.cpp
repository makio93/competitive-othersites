// 自力TLE

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
	int blen = max(1, (int)ceil(sqrt(q))), m = (n+blen-1) / blen;
	vector<vector<tuple<int, int, int>>> qlst(m);
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li; --ri;
		qlst[li/blen].emplace_back(ri, li, i);
	}
	rep(i, m) sort(all(qlst[i]));
	int ai = 0, bi = 0;
	set<int> alst;
	multiset<int> dlst;
	alst.insert(a[0]);
	vector<int> res(q);
	auto add = [&](int id) -> void {
		if (!dlst.empty()) {
			auto itr = alst.upper_bound(a[id]);
			if (itr!=alst.end() && itr!=alst.begin()) dlst.erase(dlst.find(*itr-*prev(itr)));
		}
		alst.insert(a[id]);
		auto litr = alst.lower_bound(a[id]), ritr = alst.upper_bound(a[id]);
		if (litr != alst.begin()) dlst.insert(*litr-*prev(litr));
		if (ritr != alst.end()) dlst.insert(*ritr-*prev(ritr));
	};
	auto del = [&](int id) -> void {
		auto itr = alst.find(a[id]);
		if (next(itr) != alst.end()) dlst.erase(dlst.find(*next(itr)-*itr));
		if (itr != alst.begin()) dlst.erase(dlst.find(*itr-*prev(itr)));
		itr = alst.erase(itr);
		if (itr!=alst.end() && itr!=alst.begin()) dlst.insert(*itr-*prev(itr));
	};
	rep(i, m) {
		int ql = qlst[i].size(), di = (i%2 == 0) ? 1 : -1, si = (i%2 == 0) ? 0 : ql-1;
		for (int j=si; j>=0&&j<ql; j+=di) {
			int li = get<1>(qlst[i][j]), ri = get<0>(qlst[i][j]), id = get<2>(qlst[i][j]);
			while (bi < ri) {
				++bi;
				add(bi);
			}
			while (ai < li) {
				del(ai);
				++ai;
			}
			while (ai > li) {
				--ai;
				add(ai);
			}
			while (bi > ri) {
				del(bi);
				--bi;
			}
			res[id] = *dlst.begin();
		}
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
