#include <bits/stdc++.h>
using namespace std;

struct Trie {
    int ch[2];
    Trie() { ch[0] = ch[1] = -1; }
};

vector<Trie> trie;

void insert(int x) {
    int node = 0;
    for (int b = 29; b >= 0; b--) {
        int bit = (x >> b) & 1;
        if (trie[node].ch[bit] == -1) {
            trie[node].ch[bit] = trie.size();
            trie.push_back(Trie());
        }
        node = trie[node].ch[bit];
    }
}

int queryMax(int x) {
    int node = 0, res = 0;
    for (int b = 29; b >= 0; b--) {
        int bit = (x >> b) & 1;
        int want = 1 - bit;
        if (trie[node].ch[want] != -1) {
            res |= (1 << b);
            node = trie[node].ch[want];
        } else {
            node = trie[node].ch[bit];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        
        trie.clear();
        trie.push_back(Trie());
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) ans = max(ans, queryMax(a[i]));
            insert(a[i]);
        }
        cout << ans << "\n";
    }
}