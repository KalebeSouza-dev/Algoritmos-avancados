#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define pb push_back
#define read_vec(v,n) for(int i = 0; i < n; i++) cin >> v[i]

const int MAX = 10e5 + 10;

vector<ll> a;
vector<ll> tree;
int n, q; 

inline int left(int id) { return (id << 1); }
inline int right(int id) { return (id << 1) | 1; }

void build(int p, int l, int r){
    if (l == r) tree[p] = a[l];
    else{
        int m = (l + r) >> 1;
        build(left(p), l, m);
        build(right(p), m + 1, r);

        tree[p] = tree[left(p)] + tree[right(p)];
    }
}
void muda(int id, int l, int r, int pos, ll val) {
        if (l == r) tree[id] = val;
        else {
            int mid = (l + r) >> 1;

            if (pos <= mid) muda(left(id), l, mid, pos, val);
            else muda(right(id), mid + 1, r, pos, val);

            tree[id] = tree[left(id)] + tree[right(id)];
        }
}
ll query(int id, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return 0;
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }

void solve(){
    int t, i;
    ll j;
    cin >> t >> i >> j;

    if (t == 1) muda(1, 0, n - 1, i - 1, j);
    else {
        cout << query(1, 0, n - 1, i - 1, j - 1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;

    a.resize(n);
    tree.resize(4 * n);

    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);

    while (q--) solve();
    
    return 0;
}