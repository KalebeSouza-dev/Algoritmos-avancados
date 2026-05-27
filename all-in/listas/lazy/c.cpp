#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll inf = 1e18;
template<class T> struct seg_tree {
    struct node {
        T x;
        node() : x(0) {}
        node(T x) : x(x) {}
        node operator+(const node &o) const {
            return node(x + o.x);
        }
    };
    int n;
    vector<node> tree;
    vector<T> lazy;
    seg_tree(vector<T> a) {
        n = a.size();
        tree.resize(n * 4);
        lazy.resize(n * 4);
        build(1, 0, n - 1, a);
    }
    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }
    void build(int id, int l, int r, const vector<T> &a) {
        if (l == r) tree[id] = node(a[l]);
        else {
            int m = (l + r) >> 1;
            build(left(id), l, m, a);
            build(right(id), m + 1, r, a);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    inline void push(int id, int l, int r) {
        if (lazy[id]) {
            tree[id].x += (r - l + 1) * lazy[id];
            if (l != r) {
                lazy[left(id)] += lazy[id];
                lazy[right(id)] += lazy[id];
            }
            lazy[id] = 0;
        }
    }
    void update(int id, int l, int r, int lq, int rq, T val) {
        push(id, l, r);
        if (l > rq || r < lq) return;
        if (lq <= l && r <= rq) {
            lazy[id] += val;
            push(id, l, r);
        } else {
            int mid = (l + r) >> 1;
            update(left(id), l, mid, lq, rq, val);
            update(right(id), mid + 1, r, lq, rq, val);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    node query(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if (l > rq || r < lq) return node();
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }
    void update(int l, int r, T val) { update(1, 0, n - 1, l, r, val); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve_tc(){
    int n, c; cin >> n >> c;
    vector<ll> arr(n+1, 0);
    seg_tree<ll> lz(arr);

    while(c--){
        int k; cin >> k;
        if (k){
            int l, r; cin >> l >> r;
            auto out = lz.query(l, r);
            cout << out.x << endl;
        } else {
            int a, b; ll u; cin >> a >> b >> u;
            lz.update(a, b, u);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento