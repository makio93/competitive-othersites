#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    cin >> q;
    for (int i=0; i<q; ++i) {
        int qi;
        cin >> qi;
        if (qi == 1) {
            int ai;
            string bi;
            cin >> ai >> bi;
            --ai;
            a[ai] = bi;
        }
        else if (qi == 2) {
            string xi;
            cin >> xi;
            a.push_back(xi);
        }
        else {
            int m = a.size();
            for (int i=0; i<m; ++i) printf("%s%c", a[i].c_str(), (i<m-1?' ':'\n'));
        }
    }
    return 0;
}
