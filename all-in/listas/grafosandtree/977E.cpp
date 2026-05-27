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
vector<vi> ilhas;
vi ilha;

void dfs(int u, int p){
    vis[u] = true;
    ilha.pb(u);
    // for (auto i : ilha) cout << i << " "; cout << endl;
    for(auto v : adj[u]){
        if (v == p) continue;
        if (!vis[v]){
            dfs(v, u);
        }
    }
}

bool check_ilha(vi& ilha){
    for (auto i : ilha){
        if (sz(adj[i]) != 2) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    adj.assign(n+1,vi());
    vis.assign(n+1, false);
    
    int u, v;
    while (m--){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    rep (i, 1, n){
        if (!vis[i]){
            ilha.clear();
            dfs(i, -1);
            ilhas.pb(ilha);
        }
    }

    int ciclos = 0;
    for (auto ilha : ilhas){
        // for (auto i : ilha) cout << i << " ";
        // cout << endl;
        if (check_ilha(ilha)) ciclos++;
    }   
    
    // for(auto li : adj){
    //     for (auto i : li) cout << i << " ";
    //     cout << endl;
    // }

    cout << ciclos << endl;

    return 0;
}

//maldito talento