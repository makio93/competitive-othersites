#include <bits/stdc++.h>
using namespace std;

// バチャ本番AC

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length(), lid = 0;
        for (int i=0; i<=n; ++i) {
            if (i==n || title[i]==' ') {
                if (i-lid <= 2) { for (int j=lid; j<i; ++j) if (isupper(title[j])) title[j] = tolower(title[j]); }
                else {
                    if (islower(title[lid])) title[lid] = toupper(title[lid]);
                    for (int j=lid+1; j<i; ++j) if (isupper(title[j])) title[j] = tolower(title[j]);
                }
                lid = i + 1;
            }
        }
        return title;
    }
};
