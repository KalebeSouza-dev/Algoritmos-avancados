#include <bits/stdc++.h>
using namespace std;

struct Node {
    int prefix_count = 0;
    Node* pont[26] = {};
};

struct Trie {
    Node* root = new Node();

    void update(const string& s, int start) {
        Node* cur = root;
        for (int i = start; i < (int)s.size(); i++) {
            int idx = s[i] - 'a';
            if (!cur->pont[idx])
                cur->pont[idx] = new Node();
            cur = cur->pont[idx];
            cur->prefix_count++;
        }
    }

    int query(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->pont[i]) return 0;
            cur = cur->pont[i];
        }
        return cur->prefix_count;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    Trie trie;
    for (int i = 0; i < n; i++)
        trie.update(s, i);

    int k;
    cin >> k;
    while (k--) {
        string p;
        cin >> p;
        cout << (trie.query(p) > 0 ? "YES" : "NO") << "\n";
    }
}