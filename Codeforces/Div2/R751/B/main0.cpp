#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, q;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		vector<vector<int>> alst;
		alst.push_back(a);
		while (1) {
			unordered_map<int, int> acnt;
			rep(i, n) acnt[alst.back()[i]]++;
			vector<int> na(n);
			rep(i, n) na[i] = acnt[alst.back()[i]];
			if (alst.back() == na) break;
			alst.push_back(na);
		}
		int alen = alst.size();
		cin >> q;
		rep(i, q) {
			int xi, ki;
			cin >> xi >> ki;
			--xi;
			if (ki < alen) cout << alst[ki][xi] << endl;
			else cout << alst.back()[xi] << endl;
		}
	}
	return 0;
}
