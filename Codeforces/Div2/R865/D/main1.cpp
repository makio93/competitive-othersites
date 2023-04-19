// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

void output(vector<int>& vlst1, vector<int>& vlst2) {
	int n = vlst1.size();
	cout << "!";
	rep(i, n) cout << " " << vlst1[i];
	rep(i, n) cout << " " << vlst2[i];
	cout << endl;
	int val;
	cin >> val;
	if (val == -2) exit(0);
}

void query1(int xi) {
	cout << "+ " << xi << endl;
	int val;
	cin >> val;
	if (val == -2) exit(0);
}

int query2(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int val;
	cin >> val;
	if (val == -2) exit(0);
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> res1(n), res2(n);
		if (n == 2) {
			rep(i, n) res1[i] = i + 1;
			rep(i, n) res2[i] = n - i;
			output(res1, res2);
			continue;
		}
		query1(n+1); query1(n+2);
		vector<int> ord(n);
		int li = 1, ri = n;
		rep(i, n) {
			if (i%2 == 0) {
				ord[i] = li;
				++li;
			}
			else {
				ord[i] = ri;
				--ri;
			}
		}
		pair<int, int> mval = { -1, -1 };
		rep3(i, 1, n) mval = max(mval, { query2(1, i+1), i });
		int si = mval.second;
		res1[si] = ord[0];
		res2[si] = ord[n-1];
		rep(i, n) if (i != si) {
			int val = query2(si+1, i+1);
			res1[i] = ord[val];
			res2[i] = ord[n-1-val];
		}
		output(res1, res2);
	}
	return 0;
}
