#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    cout << n.substr(0, 2) << ',';
    cout << n.substr(2, 3) << ',';
    cout << n.substr(5, 3) << endl;
    return 0;
}
