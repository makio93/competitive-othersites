// 学習1回目,解説AC1-2

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    string left, right;
    int llen, rlen;
public:
    TextEditor() {
        llen = 0;
        rlen = 0;
    }
    void addText(string text) {
        int tlen = text.length();
        left += text;
        llen += tlen;
    }
    int deleteText(int k) {
        int tlen = min(k, llen);
        left.resize(llen-tlen);
        llen -= tlen;
        return tlen;
    }
    string cursorLeft(int k) {
        int tlen = min(k, llen);
        right.insert(right.end(), left.rbegin(), left.rbegin()+tlen);
        rlen += tlen;
        left.resize(llen-tlen);
        llen -= tlen;
        int slen = min(10, llen);
        return left.substr(llen-slen, slen);
    }
    string cursorRight(int k) {
        int tlen = min(k, rlen);
        left.insert(left.end(), right.rbegin(), right.rbegin()+tlen);
        llen += tlen;
        right.resize(rlen-tlen);
        rlen -= tlen;
        int slen = min(10, llen);
        return left.substr(llen-slen, slen);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */