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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<tuple<bool, int, bool>> alst;
	rep(i, n) {
		if (a[i] == 0) {
			if ((i-1<0 || a[i-1]==0) && (i+1>=n || a[i+1]==0)) alst.emplace_back(true, 0, true);
			else continue;
		}
		else {
			if (i-1<0 || a[i-1]==0) {
				if (!alst.empty() && get<1>(alst.back())!=0 && a[i-2]==0) alst.emplace_back(true, -1, true);
				alst.emplace_back(true, a[i], true);
			}
			else get<1>(alst.back()) = max(get<1>(alst.back()), a[i]);
			if (i-1>=0 && a[i-1]==0) get<0>(alst.back()) = false;
			if (i+1<n && a[i+1]==0) get<2>(alst.back()) = false;
		}
	}
	int m = alst.size(), res = 0;
	rep(i, m) {
		if (get<1>(alst[i]) == -1) continue;
		++res;
		if (get<1>(alst[i]) == 1) {
			if (!get<0>(alst[i])) {
				get<0>(alst[i]) = true;
				if (i-1 >= 0) get<2>(alst[i-1]) = true;
			}
			else {
				get<2>(alst[i]) = true;
				if (i+1 < m) get<0>(alst[i+1]) = true;
			}
		}
		else if (get<1>(alst[i]) == 2) {
			get<0>(alst[i]) = true;
			if (i-1 >= 0) get<2>(alst[i-1]) = true;
			get<2>(alst[i]) = true;
			if (i+1 < m) get<0>(alst[i+1]) = true;
		}
	}
	rep(i, m) {
		if (!get<0>(alst[i]) && get<1>(alst[i])==1) ++res;
		if (!get<2>(alst[i]) && get<1>(alst[i])==1) ++res;
	}
	cout << res << endl;
	return 0;
}
