#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main() {
	int n, k;
	cin >> n >> k;
	bool pat = false;
	if ((k+1)%2 == 1) pat = true;
	else {
		int pcnt = 0, tval = k+1;
		while (tval%2 == 0) {
			tval /= 2;
			++pcnt;
		}
		if (pcnt%2 == 0) pat = true;
	}
	vector<int> res;
	int wval = (n-1) % (k+1);
	if (pat) {
		if (wval == 0) res.push_back(0);
		else {
			res.push_back(wval);
			if (wval%2==0 && (wval/2+(k+1))%2==1) res.push_back(wval/2);
		}
	}
	else {
		if (wval == 0) {
			if (k+1 == n-1) res.push_back(0);
			else res.push_back(k);
		}
		else if (wval == 1) {
			if ((n-2)/(k+1) <= 1) res.push_back(1);
			else res.push_back(0);
		}
		else {
			if ((n-wval-1)/(k+1) <= 1) res.push_back(wval);
			else {
				res.push_back(wval-1);
				if ((n-wval-1)/(k+1)<=2 && (wval-1)%2==0 && ((wval-1)/2+(k+2))%2==1) res.push_back((wval-1)/2);
				else if ((n-wval-1)/(k+1)>2 && (wval-1)%2==0 && ((wval-1)/2+(k+1))%2==1) res.push_back((wval-1)/2);
			}
		}
	}
	sort(all(res));
	for (int val : res) cout << val << endl;
	return 0;
}
