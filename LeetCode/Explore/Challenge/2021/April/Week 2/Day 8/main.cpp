#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, string> letters = { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, 
        { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
    void dfs(string& origin, vector<string>& res, string nstr="", int d=0) {
        if (d == (int)(origin.length())) res.push_back(nstr);
        else {
            for (int i=0; i<(int)(letters[origin[d]].length()); ++i) {
                nstr += letters[origin[d]][i];
                dfs(origin, res, nstr, d+1);
                nstr.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if (n > 0) dfs(digits, res);
        return res;
    }
};

int main(){
    Solution cl;
    string digits;
    cin >> digits;
    auto res = cl.letterCombinations(digits);
    for (int i=0; i<(int)(res.size()); ++i) printf("%s%c", res[i].c_str(), (i<(int)(res.size())-1?' ':'\n'));
    return 0;
}
