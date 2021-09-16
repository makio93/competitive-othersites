#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << ((m+24-n)%24) << endl;
    return 0;
}
