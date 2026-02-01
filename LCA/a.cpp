#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN = 1e5 + 10;
#define pb push_back

const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int prof[MAXN];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < LOG; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v]) {
        if (u == p) continue;
        prof[u] = prof[v] + 1;
        dfs(u, v);
    }
}
int lca(int a, int b) {
    if (prof[a] < prof[b]) swap(a, b);

    int k = prof[a] - prof[b];
    for (int i = LOG - 1; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--)
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }

    return up[a][0];
}

void solve_tc(){
    int n; cin >> n;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        for (int j = 0; j < LOG; j++)
            up[i][j] = 0;
        prof[i] = 0;
    }

    vector<bool> pai(n + 1, false);
    for (int i = 1; i < n + 1; i ++){
        int q, x; cin >> q;
        while(q --){
            cin >> x;
            adj[i].pb(x);
            pai[x] = true;        
        }
    }

    int raiz = 1;
    for (int i = 1; i <= n; i++)
        if (!pai[i]) {
            raiz = i;
            break;
        }

    prof[raiz] = 0;
    dfs(raiz, raiz);
    
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ":" << endl;
        solve_tc();
    }
    
    return 0;
}