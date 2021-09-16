#include <iostream>
using namespace std;

int main() {
    int l, a, b;
    cin >> l >> a >> b;
    if (a-b <= 0) cout << -1 << endl;
    else cout <<((l+(a-b-1))/(a-b)) << endl;
    return 0;
}
