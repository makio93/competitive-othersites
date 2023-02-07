#include <bits/stdc++.h>
using namespace std;

// 自力AC

class CombinationIterator {
    int len;
    string tar, str;
public:
    CombinationIterator(string characters, int combinationLength) {
        tar = characters;
        len = combinationLength;
        str = tar.substr(0, len);
    }
    string next() {
        string res = str;
        do {
            while (!str.empty() && tar.find(str.back())+1>=(int)(tar.length())) str.pop_back();
            if (!str.empty()) {
                str.back() = tar[tar.find(str.back())+1];
                if (tar.length()-tar.find(str.back())-1 < len-str.length()) str.pop_back();
                else str += tar.substr(tar.find(str.back())+1, len-str.length());
            }
        } while (!str.empty() && str.length()<len);
        return res;
    }
    bool hasNext() {
        return (!str.empty());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
