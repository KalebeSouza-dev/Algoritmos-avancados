#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// @brenner
template<class T> struct seg_tree {
    struct node {
        T x;
        node() : x(LLONG_MAX) {}
        node(T x) : x(x) {}
        node operator + (const node &o) const {
            return node(min(x, o.x));
        }
    };
    int n;
    vector<node> tree;
    seg_tree(int n) : n(n), tree(n * 4) {}

    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }

    void set(int id, int l, int r, int pos, T val) {
        if (l == r) tree[id] = node(val);
        else {
            int mid = (l + r) >> 1;
            if (pos <= mid) set(left(id), l, mid, pos, val);
            else set(right(id), mid + 1, r, pos, val);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }

    node query(int id, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return node();
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }

    void set(int pos, T val) { set(1, 0, n - 1, pos, val); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vi arr(n);
    
    seg_tree<ll> sg(n);
    rep(i, 0, n) {
        cin >> arr[i];
        sg.set(i, arr[i]);
    } 

    while(q--){
        int t; cin >> t;
        if (t == 1){
            int u, v; cin >> u >>v;
            sg.set(u, v);
        } else {
            int l, r; cin >> l >> r;
            cout << sg.query(l, r-1).x << endl;
        }
    }

    return 0;
}