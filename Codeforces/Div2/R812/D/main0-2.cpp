// 本番AC

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
		vector<int> vlst;
		rep3(i, 1, (1<<n)+1) vlst.push_back(i);
		while ((int)(vlst.size()) >= 4) {
			int vlen = vlst.size();
			vector<int> nlst;
			for (int i=0; i<vlen; i+=4) {
				cout << "? " << vlst[i] << ' ' << vlst[i+2] << endl;
				cout.flush();
				int rval;
				cin >> rval;
				if (rval == 0) {
					cout << "? " << vlst[i+1] << ' ' << vlst[i+3] << endl;
					cout.flush();
					int sval;
					cin >> sval;
					if (sval == 1) nlst.push_back(vlst[i+1]);
					else nlst.push_back(vlst[i+3]);
				}
				else if (rval == 1) {
					cout << "? " << vlst[i] << ' ' << vlst[i+3] << endl;
					cout.flush();
					int sval;
					cin >> sval;
					if (sval == 1) nlst.push_back(vlst[i]);
					else nlst.push_back(vlst[i+3]);
				}
				else {
					cout << "? " << vlst[i+2] << ' ' << vlst[i+1] << endl;
					cout.flush();
					int sval;
					cin >> sval;
					if (sval == 1) nlst.push_back(vlst[i+2]);
					else nlst.push_back(vlst[i+1]);
				}
			}
			swap(nlst, vlst);
		}
		if ((int)(vlst.size()) >= 2) {
			vector<int> nlst;
			cout << "? " << vlst[0] << ' ' << vlst[1] << endl;
			cout.flush();
			int sval;
			cin >> sval;
			if (sval == 1) nlst.push_back(vlst[0]);
			else nlst.push_back(vlst[1]);
			swap(nlst, vlst);
		}
		cout << "! " << vlst[0] << endl;
		cout.flush();
	}
	return 0;
}
