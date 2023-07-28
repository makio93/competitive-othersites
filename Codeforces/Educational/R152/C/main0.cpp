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
		int n, m;
		string s;
		cin >> n >> m >> s;
		vector<int> l(m), r(m);
		rep(i, m) {
			cin >> l[i] >> r[i];
			l[i]--; r[i]--;
		}
		vector<int> clst;
		clst.push_back(0);
		rep3(i, 1, n) if (s[i] != s[i-1]) clst.push_back(i);
		vector<pair<int, int>> plst;
		rep(i, m) {
			int cli = upper_bound(all(clst), l[i]) - clst.begin() - 1, cri = upper_bound(all(clst), r[i]) - clst.begin() - 1;
			if (cli == cri || (cli+1 == cri && s[l[i]]=='0' && s[r[i]]=='1')) plst.emplace_back(-1, -1);
			else {
				int li = l[i], ri = r[i];
				if (s[l[i]] == '0') li = clst[cli+1];
				if (s[r[i]] == '1') ri = clst[cri] - 1;
				plst.emplace_back(li, ri);
			}
		}
		sort(all(plst));
		plst.erase(unique(all(plst)), plst.end());
		cout << (int)(plst.size()) << endl;
	}
	return 0;
}
