// 学習1回目,解説AC1-3

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    list<char> tlst;
    list<char>::iterator cur;
public:
    TextEditor() { cur = tlst.begin(); }
    void addText(string text) {
        for (const char& ci : text) {
            cur = tlst.insert(cur, ci);
            ++cur;
        }
    }
    int deleteText(int k) {
        int kcnt = 0;
        while (k>0 && cur!=tlst.begin()) {
            --cur;
            cur = tlst.erase(cur);
            --k; ++kcnt;
        }
        return kcnt;
    }
    string Display() {
        string str;
        auto tptr = cur;
        for (int i=0; i<10; ++i) {
            if (tptr == tlst.begin()) break;
            --tptr;
            str.push_back(*tptr);
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string cursorLeft(int k) {
        while (k>0 && cur!=tlst.begin()) { --cur; --k; }
        return Display();
    }
    string cursorRight(int k) {
        while (k>0 && cur!=tlst.end()) { ++cur; --k; }
        return Display();
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