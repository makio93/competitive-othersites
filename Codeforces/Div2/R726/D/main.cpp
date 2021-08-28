#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		int val = n;
		vector<pair<int, int>> pl;
		for (int i=2; i*i<=val; ++i) {
			if (val%i == 0) {
				pl.emplace_back(i, 0);
				while (val%i == 0) {
					pl.back().second++;
					val /= i;
				}
			}
		}
		if (val > 1) pl.emplace_back(val, 1);
		vector<int> vcnt(2);
		for (auto p : pl) vcnt[p.first%2] += p.second;
		int sum = vcnt[0] + vcnt[1];
		if (sum <= 1) cout << "Bob" << endl;
		else {
			bool win = false;
			if (vcnt[0]>0 && ((vcnt[0]-1)*1+vcnt[1]*2)%2==1) win = true;
			if (vcnt[1]>0 && (vcnt[0]*1+(vcnt[1]-1)*2)%2==1) win = true;
			if (win) cout << "Alice" << endl;
			else cout << "Bob" << endl;
		}
	}
	return 0;
}
