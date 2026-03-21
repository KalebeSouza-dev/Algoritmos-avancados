#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define pb push_back
#define read_vec(v,n) for(int i = 0; i < n; i++) cin >> v[i]

const int MAXN = 2e5 + 5;

inline int left(int id) { return (id << 1); }
inline int right(int id) { return (id << 1) | 1; }

struct Node {
    int open, close, full;
};

vector<Node> tree;
vector<ll> arr;
string s;
int q;

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') tree[id] = {1, 0, 0};
        else tree[id] = {0, 1, 0};
    } else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        Node L = tree[left(id)], R = tree[right(id)];
        int par = min(L.open, R.close);
        tree[id].full  = L.full + R.full + par;
        tree[id].open  = L.open + R.open - par;
        tree[id].close = L.close + R.close - par;
    }
}

Node query(int id, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return {0,0,0};
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;

        Node L = query(left(id), l, mid, lq, rq);
        Node R = query(right(id), mid + 1, r, lq, rq);

        int par = min(L.open, R.close);
        Node res;
        res.full  = L.full + R.full + par;
        res.open  = L.open + R.open - par;
        res.close = L.close + R.close - par;
        
        return res;
    }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> q;
    int n = s.length();
    s = " " + s;

    arr.resize(n);
    tree.resize(4 * n);

    build(1, 1, n);

    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << query(1, 1, n, i, j).full * 2 << endl;
    }

    return 0;
}