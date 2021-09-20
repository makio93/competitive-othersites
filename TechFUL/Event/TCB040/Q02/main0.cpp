// 本番AC

#include <iostream>
using namespace std;

int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l2<=l1 && r2>=r1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
