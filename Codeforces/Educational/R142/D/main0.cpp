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

struct TrieNode {
	int m;
	vector<TrieNode*> next;
	TrieNode(int m_) {
		next = vector<TrieNode*>(m_);
		m = m_;
	}
	void add(vector<int>& alst, int id) {
		if (id >= m) return;
		if (next[alst[id]] == nullptr) next[alst[id]] = new TrieNode(m);
		next[alst[id]]->add(alst, id+1);
	}
	int search(vector<int>& tlst, int di) {
		if (di>=m || next[tlst[di]]==nullptr) return di;
		return next[tlst[di]]->search(tlst, di+1);
	}
};

struct Trie {
	int m;
	TrieNode *root;
	Trie(int m_) {
		m = m_;
		root = new TrieNode(m);
	}
	void addlst(vector<int>& alst) { root->add(alst, 0); }
	int searchlist(vector<int>& tlst) { return root->search(tlst, 0); }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m)), ra(n, vector<int>(m));
		rep(i, n) rep(j, m) {
			cin >> a[i][j];
			a[i][j]--;
		}
		rep(i, n) rep(j, m) ra[i][a[i][j]] = j;
		Trie tr(m);
		rep(i, n) tr.addlst(ra[i]);
		vector<int> res(n);
		rep(i, n) res[i] = tr.searchlist(a[i]);
		rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	}
	return 0;
}
