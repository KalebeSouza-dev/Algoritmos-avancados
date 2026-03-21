#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); i++)
const int MAXN = 5 * 10e5 + 10;

vector<ll> tree(4 * MAXN);
vector<ll> arr(MAXN);
void build(int id, int l, int r){
    if (l == r) tree[id] = arr[l];
    else{
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        tree[id] = __gcd(tree[id * 2], tree[id * 2 + 1]);
    }
}
void update(int id, int l, int r, int pos, ll val){
    if (l == r) tree[id] = val;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid){
            update(id*2, l, mid, pos, val);
        } else {
            update(id*2+1, mid + 1, r, pos, val);
        }
        tree[id] = __gcd(tree[id*2], tree[id*2+1]);
    }
}
int query(int id, int l, int r, int e, int d, ll x){
    if (l > d || r < e) return 0;
    //if (l >= e && r <= d) return tree[id];
    if (tree[id] % x == 0) return 0;
    if (l == r) return 1;

    int mid = (l + r) / 2;
    int left = query(id*2, l, mid, e, d, x);
    if (left > 1) return 2;

    int right = query(id*2+1, mid+1, r, e, d, x);
    return min(2, left + right);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    rep(i, 1, n+1) cin >> arr[i];
    int q; cin >> q;

    build(1, 1, n);
    while(q--){
        int k, i, j, x; cin >> k;
        if (k == 1){
            cin >> i >> j >> x;
            int out = query(1,1,n, i, j, x);

            if (out <= 1) cout << "YES\n";
            else cout << "NO\n";
        } else{
            cin >> i >> j;
            update(1,1, n, i, j);
        }
    }
    return 0;
}