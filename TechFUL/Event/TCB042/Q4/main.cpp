#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<string> s(n);
    for (int i=0; i<n; ++i) cin >> s[i];
    for (int i1=0; i1<x%4; ++i1) {
        vector<string> ns(n, string(n, '.'));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) ns[j][n-i-1] = s[i][j];
        swap(ns, s);
    }
    for (int i=0; i<n; ++i) cout << s[i] << endl;
    return 0;
}
