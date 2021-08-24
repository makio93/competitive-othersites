#include <bits/stdc++.h>
using namespace std;

// 本番WA

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        word1 += (char)('a'-1);
        word2 += (char)('a'-1);
        string ans = "";
        int i1 = 0, i2 = 0;
        while (i1<n1 || i2<n2) {
            int t1 = i1, t2 = i2;
            while (word1[t1]==word2[t2] && (t1<n1||t2<n2)) { ++t1; ++t2; }
            if (t1>=n1 && t2>=n2) {
                while (i1<n1 && i2<n2) {
                    ans += word1[i1];
                    ans += word2[i2];
                    ++i1; ++i2;
                }
                break;
            }
            /*
            else if (t1 >= n1) {
                while (i1<n1 && i2<n2) {
                    ans += word1[i1];
                    ans += word2[i2];
                    ++i1; ++i2;
                }
                ans += word2.substr(i2, n2-i2);
                break;
            }
            else if (t2 >= n2) {
                while (i1<n1 && i2<n2) {
                    ans += word1[i1];
                    ans += word2[i2];
                    ++i1; ++i2;
                }
                ans += word1.substr(i1, n1-i1);
                break;
            }
            */
            else {
                if (word1[t1] >= word2[t2]) {
                    ans += word1[i1];
                    ++i1;
                }
                else {
                    ans += word2[i2];
                    ++i2;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
