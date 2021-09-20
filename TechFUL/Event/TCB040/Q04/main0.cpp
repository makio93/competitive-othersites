// 本番AC

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int lx = n * (k-1) + (n+1) / 2, rx = n * k + (n-1) / 2;
    cout << lx << ' ' << rx << endl;
    return 0;
}
