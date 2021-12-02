#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<pair<vector<int>, int>> digits(n);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(int)(words[i].length()); ++j) {
                digits[i].first.push_back((int)(order.find(words[i][j])));
            }
            digits[i].second = i;
        }
        sort(digits.begin(), digits.end());
        bool res = true;
        for (int i=0; i<n; ++i) if (digits[i].second != i) res = false;
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i=0; i<n; ++i) cin >> words[i];
    string order;
    cin >> order;
    if (cl.isAlienSorted(words, order)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
