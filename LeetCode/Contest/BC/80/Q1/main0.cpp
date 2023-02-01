// 本番AC

#include <bits/stdc++.h>
using namespace std;

const string special = "!@#$%^&*()-+";
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.length();
        if (n < 8) return false;
        bool ok = true;
        for (int i=0; i<n-1; ++i) if (password[i+1] == password[i]) ok = false;
        if (!ok) return false;
        ok = false;
        for (int i=0; i<n; ++i) if (islower(password[i])) ok = true;
        if (!ok) return false;
        ok = false;
        for (int i=0; i<n; ++i) if (isupper(password[i])) ok = true;
        if (!ok) return false;
        ok = false;
        for (int i=0; i<n; ++i) if (isdigit(password[i])) ok = true;
        if (!ok) return false;
        ok = false;
        for (int i=0; i<n; ++i) if (special.find(password[i]) != string::npos) ok = true;
        return ok;
    }
};
