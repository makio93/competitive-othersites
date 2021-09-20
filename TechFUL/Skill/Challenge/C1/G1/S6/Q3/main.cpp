#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> b;
    for (int i=0; i<n; ++i) {
        int bi;
        cin >> bi;
        b.insert(bi);
    }
    int cnt = 0;
    for (int i=0; i<m; ++i) {
        int ci;
        cin >> ci;
        if (b.find(ci) == b.end()) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
