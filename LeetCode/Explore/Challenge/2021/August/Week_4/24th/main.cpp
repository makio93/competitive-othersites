#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int pid1 = num1.find('+'), pid2 = num2.find('+');
        int a1 = stoi(num1.substr(0, pid1)), a2 = stoi(num2.substr(0, pid2));
        int b1 = stoi(num1.substr(pid1+1, n1-pid1-2)), b2 = stoi(num2.substr(pid2+1, n2-pid2-2));
        return (to_string(a1*a2-b1*b2) + '+' + to_string(a1*b2+a2*b1) + 'i');
    }
};
