// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int n, q;
	cin >> n >> q;
	dsu d(n);
	unordered_set<int> lst;
	rep(i, n) lst.insert(i);
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int ui, vi;
			cin >> ui >> vi;
			--ui; --vi;
			if (d.same(ui, vi)) continue;
			lst.erase(d.leader(ui));
			lst.erase(d.leader(vi));
			d.merge(ui, vi);
			lst.insert(d.leader(ui));
		}
		else {
			int vi;
			cin >> vi;
			--vi;
			if ((int)(lst.size()) == 1) {
				cout << -1 << endl;
				continue;
			}
			int ai = d.leader(vi);
			if (*lst.begin() == ai) ai = *next(lst.begin());
			else ai = *lst.begin();
			cout << (ai+1) << endl;
		}
	}
	return 0;
}
