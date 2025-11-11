#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define pb push_back
#define read_vec(v,n) for(int i = 0; i < n; i++) cin >> v[i]

const int MAXN = (1 << 17) + 5;

inline int left(int id) { return (id << 1); }
inline int right(int id) { return (id << 1) | 1; }

int n, m;
vector<ll> tree(4 * MAXN);
vector<int> arr(MAXN);

void build(int id, int l, int r, bool is_or){
    if (l == r) tree[id] = arr[r];
    else {
        ll mid = (l + r) / 2;
        build(left(id), l, mid, !is_or);
        build(right(id), mid + 1, r, !is_or);

        if (is_or)
            tree[id] = tree[left(id)] | tree[right(id)]; 
        else
            tree[id] = tree[left(id)] ^ tree[right(id)]; 
    }
}   

void muda(int id, int l, int r, int pos, int val, bool is_or){
    if (l == r){
        tree[id]= val;
    } else{
        ll mid = (l + r) / 2;
        if (pos <= mid){
            muda(left(id), l, mid, pos, val, !is_or);
        } else {
            muda(right(id), mid + 1, r, pos, val, !is_or);
        }

        if (is_or)
            tree[id] = tree[left(id)] | tree[right(id)]; 
        else
            tree[id] = tree[left(id)] ^ tree[right(id)]; 
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    int tam = 1 << n;
    for (int i = 1; i <= tam; i++) cin >> arr[i];
    
    build(1, 1, tam, n % 2 == 1);

    while (m --){
        int p, b; cin >> p >> b;
        muda(1, 1, tam, p, b, n % 2 == 1);
        cout << tree[1] << endl;
    }

    return 0;
}