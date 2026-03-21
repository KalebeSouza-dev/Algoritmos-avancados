#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN = 1e5 + 100;
const int BIT = 31;
int n, m, k;
vector<ll> arr(MAXN);
vector<ll> tree(4 * MAXN), lazy(4 * MAXN);
vector<vector<ll>> bit(4 * MAXN, vector<ll>(BIT));

void prop(ll id, ll l, ll r){
    ll x = lazy[id];
    if (x == 0) return;

    ll len = r - l + 1;
    for (ll b = 0; b < BIT; b++){
        if (x & (1LL << b)){
            ll um = bit[id][b];
            ll zero = len - um;
            bit[id][b] = zero;
            tree[id] += (zero - um) * (1LL << b);
        }
    }
    if (l != r){
        lazy[id*2] ^= x;
        lazy[id*2+1] ^= x;
    }
    lazy[id] = 0;
}
void build(ll id, ll l, ll r){
    if (l == r){
        tree[id] = arr[l];
        for (ll k = 0; k < BIT; k++)
            bit[id][k] = ((arr[l] >> k) & 1);
        return;
    }
    ll mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    tree[id] = tree[id*2] + tree[id*2+1];

    for (ll k = 0; k < BIT; k++)
        bit[id][k] = bit[id*2][k] + bit[id*2+1][k];
}
void update(ll id, ll l, ll r, ll e, ll d, ll x){
    prop(id, l, r);
    if (l > d || r < e) return;

    if (l >= e && r <= d){
        ll len = r - l + 1;
        for (ll b = 0; b < BIT; b++){
            if (x & (1LL << b)){
                ll um = bit[id][b];
                ll zero = len - um;
                bit[id][b] = (ll)zero;
                tree[id] += (zero - um) * (1LL << b);
            }
        }
        if (l != r){
            lazy[id*2] ^= x;
            lazy[id*2+1] ^= x;
        }
        return;
    }

    ll mid = (l + r) / 2;
    update(id*2, l, mid, e, d, x);
    update(id*2+1, mid+1, r, e, d, x);

    prop(id*2, l, mid);
    prop(id*2+1, mid+1, r);

    tree[id] = tree[id*2] + tree[id*2+1];
    for (ll b = 0; b < BIT; b++)
        bit[id][b] = bit[id*2][b] + bit[id*2+1][b];
}
ll query(ll id, ll l, ll r, ll e, ll d){
    prop(id, l, r);
    if (l > d || r < e) return 0;
    if (l >= e && r <= d) return tree[id];
    
    ll mid = (l + r) / 2;
    return (query(id*2, l, mid, e, d) + query(id*2+1, mid+1,r, e, d));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    cin >> m;
    build(1, 1, n);
    while(m--){
        ll l, r;
        cin >> k >> l >> r;
        if (k == 2){
            ll x; cin >> x;
            update(1, 1, n, l, r, x);
        } else {
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}