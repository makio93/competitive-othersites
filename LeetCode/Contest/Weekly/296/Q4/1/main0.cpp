// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    struct CharNode {
        char c;
        CharNode *prev, *next;
        CharNode(char c_='\0', CharNode* prv=nullptr, CharNode* nxt=nullptr) : c(c_), prev(prv), next(nxt) {}
    };
    CharNode *cur;
public:
    TextEditor() { cur = new CharNode(); }
    void addText(string text) {
        CharNode *rnode = cur->next;
        for (const char& ci : text) {
            cur->next = new CharNode(ci, cur, rnode);
            cur = cur->next;
            if (rnode != nullptr) rnode->prev = cur;
        }
    }
    int deleteText(int k) {
        int kcnt = 0;
        CharNode *rnode = cur->next;
        while (kcnt<k && cur->c!='\0') {
            cur = cur->prev;
            delete cur->next;
            cur->next = rnode;
            if (rnode != nullptr) rnode->prev = cur;
            ++kcnt;
        }
        return kcnt;
    }
    string left() {
        string lstr;
        CharNode *tcur = cur;
        int kcnt = 10;
        while (kcnt>0 && tcur->c!='\0') {
            lstr.push_back(tcur->c);
            tcur = tcur->prev;
            --kcnt;
        }
        reverse(lstr.begin(), lstr.end());
        return lstr;
    }
    string cursorLeft(int k) {
        while (k>0 && cur->c!='\0') {
            cur = cur->prev;
            --k;
        }
        return left();
    }
    string cursorRight(int k) {
        while (k>0 && cur->next!=nullptr) {
            cur = cur->next;
            --k;
        }
        return left();
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