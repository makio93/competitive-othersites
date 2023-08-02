// 解説AC

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

struct fraction {
	ll num, den;
	fraction(ll num=0, ll den=1) {
		this->num = num, this->den = den;
		if (this->num == 0 && this->den == 0) return;
		if (this->den == 0) this->num /= abs(this->num);
		else if (this->num == 0) this->den /= abs(this->den);
		else {
			ll gval = gcd(abs(this->num), abs(this->den));
			this->num /= gval, this->den /= gval;
		}
	}
	bool operator<(const fraction& other) const {
		return make_pair(num, den) < make_pair(other.num, other.den);
	}
	bool operator<=(const fraction& other) const {
		return make_pair(num, den) <= make_pair(other.num, other.den);
	}
};

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	if (n <= 1) {
		cout << 0 << endl;
		return 0;
	}
	unordered_set<int> st;
	rep(i, n) {
		vector<pair<fraction, int>> flst;
		rep(j, n) if (j != i) flst.emplace_back(fraction(y[j]-y[i], x[j]-x[i]), j);
		set<fraction> fst;
		rep(j, n-1) fst.insert(flst[j].first);
		for (auto& [fr, id] : flst) {
			fraction tfl(-fr.num, -fr.den);
			if (fst.find(tfl) != fst.end()) st.insert(id);
		}
	}
	cout << (int)(st.size()) << endl;
	return 0;
}
