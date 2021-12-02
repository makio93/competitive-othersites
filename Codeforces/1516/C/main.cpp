#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int sum = 0;
	rep(i, n) sum += a[i];
	if (sum%2==1) {
		cout << 0 << endl;
		return 0;
	}
	int lsum = 0, lid = -1;
	rep(i, n) {
		lsum += a[i];
		if (lsum >= sum / 2) {
			lid = i;
			break;
		}
	}
	int dlen = abs(lsum-(sum-lsum)) / 2;
	bool ok = false;
	rep(i, lid+1) for (int j=lid+1; j<n; ++j) {
		if (abs(a[i]-a[j]) == dlen) ok = true;
	}
	if (!ok) {
		cout << 0 << endl;
		return 0;
	}
	bool odd = false;
	int oval = -1;
	rep(i, n) {
		if (a[i]%2==1) {
			odd = true;
			oval = i+1;
			break;
		}
	}
	if (odd) {
		cout << 1 << endl;
		cout << oval << endl;
		return 0;
	}
	set<int> dlst;
	map<int, vector<int>> acnt;
	rep(i, n) acnt[a[i]].push_back(i+1);
	rep(i, n) for (int j=i+1; j<n; ++j) if (a[i] != a[j]) dlst.insert(abs(a[i]-a[j]));
	vector<int> res;
	for (auto itr=acnt.begin(); itr!=acnt.end(); ++itr) if (dlst.find(itr->first) != dlst.end()) res = itr->second;
	cout << (int)(res.size()) << endl;
	if ((int)(res.size()) > 0) rep(i, (int)(res.size())) printf("%d%c", res[i], (i<(int)(res.size())-1?' ':'\n'));
	else cout << endl;
	return 0;
}
