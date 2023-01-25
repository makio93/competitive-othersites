// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    list<char> data;
    list<char>::iterator cur;
public:
    TextEditor() { cur = data.begin(); }
    void addText(string text) { data.insert(cur, text.begin(), text.end()); }
    int deleteText(int k) {
        int kcnt = 0;
        while (k>0 && cur!=data.begin()) {
            --cur;
            cur = data.erase(cur);
            --k;
            ++kcnt;
        }
        return kcnt;
    }
    string display() {
        string str;
        auto titr = cur;
        for (int i=0; i<10; ++i) {
            if (titr == data.begin()) break;
            --titr;
            str.push_back(*titr);
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string cursorLeft(int k) {
        while (k>0 && cur!=data.begin()) { --cur; --k; }
        return display();
    }
    string cursorRight(int k) {
        while (k>0 && cur!=data.end()) { ++cur; --k; }
        return display();
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
