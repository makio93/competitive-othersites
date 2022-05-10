// 

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
		string s;
		cin >> n >> s;
		vector<vector<pair<char, int>>> run;
		run.push_back(vector<pair<char, int>>(0));
		rep(i, n) {
			if (s[i] == 'W') run.push_back(vector<pair<char, int>>(0));
			else if (!run.back().empty()) {
				if (s[i] == run.back().back().first) run.back().back().second++;
				else run.back().emplace_back(s[i], 1);
			}
			else run.back().emplace_back(s[i], 1);
		}
		bool res = true;
		for (auto& vec : run) if ((int)(vec.size()) == 1) {
			res = false;
			break;
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
