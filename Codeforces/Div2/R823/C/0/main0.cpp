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
		string s;
		cin >> s;
		string res, t = s;
		for (char ci='0'; ci<='9'; ++ci) {
			if (t.empty()) break;
			bool lead = (t.front() == ci), sep = false;
			int len = t.length();
			rep(i, len) {
				if (t[i] != ci) {
					if (lead) lead = false;
				}
				else {
					if (!lead) sep = true;
				}
			}
			string nt;
			if (!sep) {
				rep(i, len) {
					if (t[i] == ci) res.push_back(ci);
					else nt.push_back(t[i]);
				}
			}
			else {
				int tid = len;
				repr(i, len) if (t[i] == ci) {
					tid = i + 1;
					break;
				}
				rep(i, len) {
					if (t[i] == ci) res.push_back(ci);
					else {
						if (i < tid) nt.push_back(min('9', (char)(t[i]+1)));
						else nt.push_back(t[i]);
					}
				}
			}
			swap(nt, t);
		}
		cout << res << endl;
	}
	return 0;
}
