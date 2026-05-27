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

vector<vector<pii>> adj;
vector<bool> vis;
ll ans = 0;

void dfs(int u, int p, ll custo){
    ans = max<ll>(ans, custo);
    
    for(auto [v, c] : adj[u]){
        if (v == p) continue;

        dfs(v, u, custo + c);
        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    adj.assign(n+1, vector<pii>());
    vis.assign(n+1, false);

    for (int i = 0; i < n-1; i++){
        int u, v, c; cin >> u >> v >> c;

        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }

    dfs(0, -1, 0);

    cout << ans << endl;

    return 0;
}

//maldito talento