#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

struct query{
    char key;
    int number;
};
vector<query> qs;
vector<int> freq, tree, vals;
int N;

int cont_f = 0;
// I - insert X, se nao estiver em S;
// D - Delete X, se estiver em S;
// K - retorna o indice do k-esimo valor, invalid se x > len
// S - retorna o numero de numeros menores que x
int buscaBinaria(int x) {
    // retorna o indice de x no array vals
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
} 
void update(int id, int l, int r, int pos, int k){
    if (l == r) tree[id] += k;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid) update(id*2, l, mid, pos, k);
        else update(id*2+1, mid+1, r, pos, k);

        tree[id] = tree[id*2] + tree[id*2+1];
    }
}
int queryT(int id, int l, int r, int k){
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (tree[id*2] >= k) return queryT(id*2, l, mid, k);
    else return queryT(id*2+1, mid+1, r, k - tree[id*2]);
}
int queryS(int id, int l, int r, int e, int d){
    if (d < l || r < e) return 0;
    if (e <= l && r <= d) return tree[id];
    int mid = (l + r) / 2;
    return queryS(id*2, l, mid, e, d) +
           queryS(id*2+1, mid+1, r, e, d);
}
void solve(){
    for (query x : qs){
        //cout << x.key << x.number << endl;
        int id = buscaBinaria(x.number);
        if (x.key == 'I'){
            if (freq[id] == 0){
                freq[id]++;
                cont_f++;
                update(1, 0, N-1, id, 1);
            }
        } else if (x.key == 'D'){
            if (freq[id] == 1){
                freq[id]--;
                cont_f--;
                update(1, 0, N-1, id, -1);
            }
        } else if (x.key == 'K'){
            if (x.number > cont_f) cout << "invalid\n";
            else{
                int pos = queryT(1, 0, N-1, x.number);
                cout << vals[pos] << "\n";
            }
        } else {
            if (id == 0) cout << 0 << endl;
            else {
                cout << queryS(1, 0, N-1, 0, id-1) << "\n";
            }
        }
            
        }
    // cout << cont_f << "\n";
    // for (int x : freq) cout << x << " ";
    // cout << '\n';
    // for (int x : vals) cout << x << " ";
    // cout << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    while(n--){
        //pre processa todas as chamadas
        query q;
        char key; int number;
        cin >> key >> number;
        q.key = key;
        q.number = number;

        qs.push_back(q);
    }
    for (query x : qs){
        //faz um array comprimido de todas as querys
        if (x.key == 'K') continue;
        vals.push_back(x.number);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end()); // unique joga os repetidos pro final
    freq.assign(vals.size(), 0);
    tree.assign(vals.size() * 4, 0);
    N = vals.size();

    solve();

    return 0;
}