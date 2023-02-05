// 本番WA1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const string tar = "inw";
const vector<string> tar1 = { "inn", "iww", "iin", "nww", "iiw", "nnw" }, tar2 = { "iii", "nnn", "www" };
const vector<char> ctar1 = { 'n', 'w', 'i', 'w', 'i', 'n' }, ctar2 = { 'i', 'n', 'w' };
const vector<int> itar = { 2, 1, 2, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int m;
		cin >> m;
		vector<string> s(m);
		rep(i, m) cin >> s[i];
		rep(i, m) sort(all(s[i]));
		vector<pair<pair<int, char>, pair<int, char>>> res;
		vector<vector<int>> mlst1(6), mlst2(3), mlst3(6);
		rep(i, m) {
			auto itr1 = find(all(tar1), s[i]), itr2 = find(all(tar2), s[i]);
			if (itr1 != tar1.end()) {
				int id = itr1 - tar1.begin();
				mlst1[id].push_back(i);
			}
			else if (itr2 != tar2.end()) {
				int id = itr2 - tar2.begin();
				mlst2[id].push_back(i);
			}
		}
		rep(i, 3) {
			int mlen = (int)min(mlst1[i*2].size(), mlst1[i*2+1].size());
			rep(j, mlen) res.emplace_back(make_pair(mlst1[i*2][j]+1, ctar1[i*2]), make_pair(mlst1[i*2+1][j]+1, ctar1[i*2+1]));
			if ((int)(mlst1[i*2].size()) > mlen) rep3(j, mlen, mlst1[i*2].size()) mlst3[i*2].push_back(mlst1[i*2][j]);
			else if ((int)(mlst1[i*2+1].size()) > mlen) rep3(j, mlen, mlst1[i*2+1].size()) mlst3[i*2+1].push_back(mlst1[i*2+1][j]);
		}
		rep(i, 3) {
			rep(j, 6) if (itar[j] == i) {
				rep(j2, (int)(mlst3[j].size())) res.emplace_back(make_pair(mlst3[j][j2]+1, ctar1[j]), make_pair(mlst2[i][j2]+1, ctar2[i]));
			}
		}
		int k = res.size();
		cout << k << endl;
		rep(i, k) cout << res[i].first.first << ' ' << res[i].first.second << ' ' << res[i].second.first << ' ' << res[i].second.second << endl;
	}
	return 0;
}
