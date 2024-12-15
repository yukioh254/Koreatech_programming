#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* ch[26] = {nullptr};
    Trie* fail = nullptr;
    bool end = false;

    void insert(const string& s) {
        Trie* cur = this;
        for (char c : s) {
            int idx = c - 'a';
            if (!cur->ch[idx]) cur->ch[idx] = new Trie();
            cur = cur->ch[idx];
        }
        cur->end = true;
    }

    void init() {
        queue<Trie*> q;
        this->fail = this;
        q.push(this);

        while (!q.empty()) {
            Trie* cur = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) {
                Trie* next = cur->ch[i];
                if (!next) continue;

                Trie* f = cur->fail;
                while (f != this && !f->ch[i]) f = f->fail;
                if (f->ch[i] && f->ch[i] != next) f = f->ch[i];
                next->fail = (cur == this) ? this : f;
                next->end |= next->fail->end;

                q.push(next);
            }
        }
    }

    bool query(const string& s) {
        Trie* cur = this;
        for (char c : s) {
            int idx = c - 'a';
            while (cur != this && !cur->ch[idx]) cur = cur->fail;
            if (cur->ch[idx]) cur = cur->ch[idx];
            if (cur->end) return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie root;
    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        root.insert(s);
    }
    root.init();

    int Q; cin >> Q;
    while (Q--) {
        string s; cin >> s;
        cout << (root.query(s) ? "YES\n" : "NO\n");
    }

    return 0;
}
