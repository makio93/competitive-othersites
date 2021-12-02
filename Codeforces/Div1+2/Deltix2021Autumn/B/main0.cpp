#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const string tar = "abc";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> q >> s;
	set<int> aids;
	rep(i, n-2) if (s.substr(i, 3) == string("abc")) aids.insert(i);
	rep(i, q) {
		int pos;
		char ci;
		cin >> pos >> ci;
		--pos;
		if (!aids.empty()) {
			auto itr = aids.upper_bound(pos);
			if (itr != aids.begin()) {
				--itr;
				int tid = pos - (*itr);
				if (tid<3 && ci!=tar[tid]) aids.erase(itr);
			}
		}
		s[pos] = ci;
		int li = max(0, pos-2), ri = min(n-3, pos) + 1;
		rep3(j, li, ri) if (s.substr(j, 3) == string("abc")) aids.insert(j);
		cout << (int)(aids.size()) << endl;
	}
	return 0;
}
