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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		rep(i, n) cin >> a[i];
		rep(i, m) cin >> b[i];
		unordered_set<int> ast(all(a)), bst(all(b));
		vector<int> clst;
		for (auto itr=ast.begin(); itr!=ast.end(); ) {
			if (bst.find(*itr) != bst.end()) {
				clst.push_back(*itr);
				bst.erase(*itr);
				itr = ast.erase(itr);
			}
			else ++itr;
		}
		vector<pair<bool, int>> res;
		if (clst.empty()) {
			if (!ast.empty() && !bst.empty()) {
				cout << "No" << endl;
				continue;
			}
			else if (ast.empty()) {
				for (const int& vi : bst) res.emplace_back(true, vi);
			}
			else {
				for (const int& vi : ast) res.emplace_back(false, vi);
			}
		}
		else {
			for (const int& vi : clst) {
				if ((int)(res.size())/2%2 == 0) {
					res.emplace_back(false, vi);
					res.emplace_back(true, vi);
				}
				else {
					res.emplace_back(true, vi);
					res.emplace_back(false, vi);
				}
			}
			auto tmp2 = res.back();
			res.pop_back();
			auto tmp1 = res.back();
			res.pop_back();
			if (!tmp1.first) {
				for (const int& vi : ast) res.emplace_back(false, vi);
				res.push_back(tmp1);
				res.push_back(tmp2);
				for (const int& vi : bst) res.emplace_back(true, vi);
			}
			else {
				for (const int& vi : bst) res.emplace_back(true, vi);
				res.push_back(tmp1);
				res.push_back(tmp2);
				for (const int& vi : ast) res.emplace_back(false, vi);
			}
		}
		cout << "Yes" << endl;
		for (const auto& pi : res) cout << (!pi.first ? "Red" : "Blue") << ' ' << pi.second << endl;
	}
	return 0;
}
