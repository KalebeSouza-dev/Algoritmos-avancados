#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); i++)
const int MAXN = 2 * 1e5 + 10;

vector<ll> tree(4 * MAXN);
vector<ll> lazy(4 * MAXN);
vector<ll> arr(MAXN);

void build(int id, int l, int r){
    if(l == r) tree[id] = arr[l];
    else{
        int mid = (l + r) / 2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id] = max(tree[id*2], tree[id*2+1]);
    }
}
void update(int id, int l, int r,int pos, int dec){
    if (l == r) tree[id] = dec;
    else{
        int mid = (l + r) / 2;
        if (pos <= mid) update(id*2, l, mid, pos, dec);
        else update(id*2+1, mid + 1, r, pos, dec);

        tree[id] = max(tree[id*2], tree[id*2+1]);
    }
}
ll query(int id, int l, int r, int x){
    if (tree[id] < x) return -1;
    if (l == r) return l;

    int mid = (l + r) / 2;
    if (tree[id*2] >= x) return query(id*2, l, mid, x);
    else return query(id*2+1, mid+1, r, x);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    rep(i,0, n) cin >> arr[i];

    build(1, 0, n-1);
    
    int q;
    for (int i = 0; i < m; i++){
        cin >> q;
        int out = query(1,0,n-1, q);
        if (out == -1) cout << 0 << " ";
        else{
            cout << out + 1 << " ";
            arr[out] -= q;
            update(1,0,n-1, out, arr[out]);
        }
    }
    cout << endl;
    return 0;
}