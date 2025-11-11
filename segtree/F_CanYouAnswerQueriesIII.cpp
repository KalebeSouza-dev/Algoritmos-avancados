#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); i++)

const int MAXN = 5 * 10e4 + 10;
const int NEG_INF = -10e9;

struct Node{
    ll sum, maxi, pref, suf;
};

int n, q;
vector<int> arr(MAXN);
vector<Node> tree(4 * MAXN);

Node merge(Node l, Node r){
    Node res;
    res.sum = l.sum + r.sum;
    res.maxi = max({l.maxi, r.maxi, l.suf + r.pref});
    res.pref = max(l.pref, l.sum + r.pref);
    res.suf = max(r.suf, l.suf + r.sum);

    return res;
}

void update(int id, int l, int r, ll pos, ll val){
    if (l == r){
        tree[id] = {val, val, val, val};
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid){
            update(id*2, l, mid, pos, val);
        } else{
            update(id*2+1, mid + 1, r, pos, val);
        }

        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
}

Node query(int id, int l, int r, ll lq, ll rq){
    if (l > rq || r < lq) return {NEG_INF, NEG_INF, NEG_INF, NEG_INF};
    if (lq <= l && r <= rq) return tree[id];

    int mid = (l + r) / 2;

    return merge(query(id*2, l, mid, lq, rq), query(id*2+1, mid+1, r, lq, rq));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    rep(i, 1, n+1) cin >> arr[i];
    cin >> q;

    //construir sem o build
    for (int i = 1; i <= n; i++)
        update(1, 1, n, i, arr[i]);

    while (q --) {
        ll a, b, c; cin >> a >> b >> c;

        if (a == 0){
            update(1,1,n, b, c);
        } else {
            cout << query(1,1,n,b,c).maxi << endl;

        }
    }
    return 0;
}