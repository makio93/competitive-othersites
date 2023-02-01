// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int slen = sentence.length();
        vector<string> words;
        int li = 0;
        for (int i=0; i<slen; ++i) {
            if (i+1 == slen) words.push_back(sentence.substr(li, i-li+1));
            else if (sentence[i] == ' ') {
                words.push_back(sentence.substr(li, i-li));
                li = i + 1;
            }
        }
        int n = words.size();
        string res;
        auto check_digit = [](string nstr) -> bool {
            if (nstr.empty()) return false;
            int pcnt = count(nstr.begin(), nstr.end(), '.'), nlen = nstr.length();
            if (pcnt >= 2) return false;
            else if (pcnt == 1) {
                if (nstr[0]=='.' || nstr[nlen-1]=='.') return false;
                for (int i=0; i<nlen; ++i) if (nstr[i]!='.' && !isdigit(nstr[i])) return false;
                return true;
            }
            else {
                for (int i=0; i<nlen; ++i) if (!isdigit(nstr[i])) return false;
                return true;
            }
        };
        auto to_digit100 = [](string nstr) -> ll {
            int pcnt = count(nstr.begin(), nstr.end(), '.'), nlen = nstr.length();
            int pid = (pcnt == 1) ? nstr.find('.') : nlen;
            if (pid == nlen) nstr.push_back('.');
            for (int i=0; i<2; ++i) nstr.push_back('0');
            return stoll(nstr.substr(0, pid)) * 100 + stoll(nstr.substr(pid+1, 2));
        };
        for (int i=0; i<n; ++i) {
            string tmp;
            if (words[i][0]=='$' && check_digit(words[i].substr(1))) {
                ll val = to_digit100(words[i].substr(1));
                val *= (100-discount);
                val /= 100;
                string vstr = to_string(val);
                int vlen = vstr.length();
                if (vlen < 3) {
                    int sub = 3 - vlen;
                    vstr = string(sub, '0') + vstr;
                    vlen = vstr.length();
                }
                tmp.push_back('$');
                tmp += vstr.substr(0, vlen-2);
                tmp.push_back('.');
                tmp += vstr.substr(vlen-2);
            }
            else tmp = words[i];
            res += tmp;
            if (i+1 < n) res.push_back(' ');
        }
        return res;
    }
};
