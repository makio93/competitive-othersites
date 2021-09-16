#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b, sum;
    cin >> r >> g >> b;
    sum = max({r, g, b}) + min({r, g, b});
    cout << (sum - r) << ' ' << (sum - g) << ' ' << (sum - b) << endl;
    return 0;
}
