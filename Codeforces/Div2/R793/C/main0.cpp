// 本番,WA

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
		map<int, int> acnt;
		rep(i, n) acnt[a[i]]++;
		vector<int> lst1, lst2;
		for (auto pi : acnt) {
			if (pi.second == 1) {
				if (lst1.size() <= lst2.size()) lst1.push_back(pi.first);
				else lst2.push_back(pi.first);
			}
			else {
				lst1.push_back(pi.first);
				lst2.push_back(pi.first);
			}
		}
		if (lst1.size() < lst2.size()) swap(lst1, lst2);
		vector<int> lst(lst1.size()+lst2.size());
		int bi = (lst1.size()+lst2.size())%2;
		rep(i, (int)(lst1.size())) lst[i*2] = lst1[i];
		rep(i, (int)(lst2.size())) lst[(int)(lst.size())-1-bi-i*2] = lst2[i];
		int m = lst.size();
		vector<int> ldp(m, INF), rdp(m, INF);
		rep(i, m) *lower_bound(all(ldp), lst[i]) = lst[i];
		repr(i, m) *lower_bound(all(rdp), lst[i]) = lst[i];
		int lcnt = 0, rcnt = 0;
		rep(i, m) if (ldp[i] != INF) ++lcnt;
		repr(i, m) if (rdp[i] != INF) ++rcnt;
		cout << min(lcnt, rcnt) << endl;
	}
	return 0;
}
