#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); i++)
const int MAXN = 10e6 + 10;

vector<ll> tree(MAXN), lazy(MAXN);

void prop(int id, int l, int r){
    if (lazy[id] == 0) return;
    tree[id] += (r-l+1) * lazy[id];
    if(l != r){
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}
void update(int id, int l, int r, int e, int d, ll val){
    prop(id, l, r);
    if (l > d || r < e) return;
    if (l >= e && r <= d) {
        tree[id] += val * (r - l + 1);
        if (l != r){
            lazy[id*2] += val;
            lazy[id*2+1] += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    update(id*2, l, mid, e, d, val);
    update(id*2 +1, mid +1, r,  e, d, val);

    tree[id] = tree[id*2] + tree[id*2+1];
}


ll query(int id, int l, int r, int e, int d){
    prop(id, l, r);
    if (l > d || r < e) return 0;
    if (l >= e && r <= d) return tree[id];

    int mid = (l + r) / 2;

    return (query(id*2, l, mid, e, d) + query(id*2+1, mid+1, r, e, d));
}

void solve_tc(){
    int n, c; cin >> n >> c;
    for (int i = 0; i < 4*n +1; i++) {
        tree[i] = 0;
        lazy[i] = 0;
    }

    while (c--){
        int k, p, q, v; cin >> k;
        
        if (k == 0){
            cin >> p >> q >> v;
            update(1, 1, n, p, q, v);
        } else{
            cin >> p >> q;
            ll out = query(1, 1, n, p, q);
            cout << out << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    
    while(t--){
        solve_tc();
    }

    return 0;
}
