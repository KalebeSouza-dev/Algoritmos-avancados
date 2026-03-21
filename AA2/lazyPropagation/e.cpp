#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<ll,ll> pii;

vector<int> tree;

void build(int id, int l, int r){
    if(l == r) tree[id] = 1;
    else{
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}
void update(int id, int l, int r, int pos){
    if(l == r) tree[id] = 0;
    else{
        int mid = (l+r)/2;
        if(pos <= mid) update(id*2, l, mid, pos);
        else update(id*2+1, mid+1, r, pos);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}

int query(int id, int l, int r, int k){
    if(l == r) return l;
    int mid = (l+r)/2;
    if(tree[id*2] >= k) return query(id*2, l, mid, k);
    else return query(id*2+1, mid+1, r, k - tree[id*2]);
}

void solve_tc(){
    int n;
    cin >> n;
    vector<int> arr(n), out(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    tree.assign(4*n, 0);
    build(1, 1, n);

    vector<int> patentes(n);
    iota(patentes.begin(), patentes.end(), 1);

    for(int i = n-1; i >= 0; i--){
        int pos = query(1, 1, n, arr[i]+1);
        out[pos-1] = patentes.back();
        patentes.pop_back();
        update(1, 1, n, pos);
    }

    for(int i = n-1; i >= 0; i--) cout << out[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--) solve_tc();

    return 0;
}
