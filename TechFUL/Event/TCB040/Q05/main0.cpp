// 本番AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    if (n%2 == 0) cout << 0 << endl;
    else {
        int gi = 0;
        for (int i=0; i<n; i+=2) gi ^= a[i];
        cout << gi << endl;
    }
    return 0;
}
