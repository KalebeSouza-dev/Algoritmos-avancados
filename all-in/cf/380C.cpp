#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

struct segtree{
    struct node {
        int open, close, full;

        node(): open(0), close(0), full(0){};
        node(char c){
            open = 0; close = 0; full = 0;
            if (c == '(') open = 1;
            else close = 1;
        }
    };

    vector<node> tree;
    
    node merge(node l, node r){
        node res;
        int aux = min (l.open, r.close);

        res.full = l.full + r.full + aux;
        res.open = l.open + r.open - aux;
        res.close = l.close + r.close - aux;

        return res;
    }

    void build(int l, int r, string &str, int pos){
        if (l == r){
            tree[pos] = node(str[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, str, pos*2);
        build(mid+1, r, str, pos*2+1);

        tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
    }

    node query(int l, int r, int s, int e, int pos){
        if (l > e || r < s) return node();
        if (l >= s && r <= e) return tree[pos];

        int mid = (l + r) / 2;
        return merge(query(l, mid, s, e, pos*2), query(mid+1, r, s, e, pos*2+1));
    }

    segtree(int len, string str){
        tree.resize(4 * len);
        build(0, len-1, str, 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s; cin >> s;
    int n = sz(s);
    
    segtree tree(n, s);

    int q; cin >> q;
    int l, r;
    while(q--){
        cin >> l >> r;
        cout << tree.query(0, n-1, l-1, r-1, 1).full * 2 << endl;
    }
    
    return 0;
}
