#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    for (int i=0; i<n; ++i) que.emplace(a[i], i);
    int cnt = 0;
    while (!que.empty()) {
        auto elem = que.top(); que.pop();
        if (x < elem.first) break;
        x -= elem.first; ++cnt;
        que.emplace(elem.first+a[elem.second], elem.second);
    }
    cout << cnt << endl;
    return 0;
}
