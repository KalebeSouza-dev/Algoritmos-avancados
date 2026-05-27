#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<vi> adj;
vector<bool> vis;
ll qtd_v = 0, qtd_a = 0;

void dfs(int u, int p){
    vis[u] = true;
    
    qtd_v++;
    for(auto v : adj[u]){
        if (u == p) continue;
        qtd_a++;
        if (!vis[v]) {
            dfs(v, u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    adj.assign(n+1, vi());
    vis.assign(n+1, false);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool eh = true;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            qtd_v = 0, qtd_a = 0;
            dfs(i, -1);
            //cout << qtd_v << " " << qtd_a/2 << endl;
            //cout << qtd_v * (qtd_v-1) / 2 << endl;
            ll ans = 1LL * qtd_v * (qtd_v-1) / 2;
            if (ans != (1LL * qtd_a/2)) eh = false; 
        }
    }

    if (eh) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

//maldito talento