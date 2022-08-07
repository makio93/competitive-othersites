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
		int n;
		cin >> n;
		set<int> exists;
		rep3(i, 1, (1<<n)+1) exists.insert(i);
		while ((int)(exists.size()) > 1) {
			auto litr = exists.begin(), ritr = prev(exists.end());
			while (*litr < *ritr) {
				cout << "? " << (*litr) << ' ' << (*ritr) << endl;
				cout.flush();
				int rval;
				cin >> rval;
				if (rval == 1) {
					ritr = prev(exists.erase(ritr));
					++litr;
				}
				else if (rval == 2) {
					litr = exists.erase(litr);
					--ritr;
				}
				else if (rval == 0) {
					ritr = prev(exists.erase(ritr));
					litr = exists.erase(litr);
				}
				else return 0;
			}
		}
		cout << "! " << (*exists.begin()) << endl;
		cout.flush();
	}
	return 0;
}
