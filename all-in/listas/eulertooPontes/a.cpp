#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;

vector<vi> adj;
vi vis, tin, low, sub;
int temp = 0;
vector<pii> edges;
ll ans;
int n;

// tds as combinacoes de cada um dos grupos
ll len_pair(int a, int b){
    ll ans = 1LL * (a) * (a-1) / 2;
    ans += 1LL * (b) * (b-1) / 2;

    return ans;
}

void dfs(int u, int p = -1){
    vis[u] = true;
    tin[u] = low[u] = temp++;
    sub[u] = 1;

    for(auto v : adj[u]){
        if (v == p) continue;

        if (vis[v]){
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);

            sub[u] += sub[v];

            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]){
                edges.pb({u, v});

                ll out = len_pair(sub[v], n - sub[v]);
                ans = min(ans, out);
            }
        }
    }
}

void solve_tc(){
    int m; cin >> n >> m;

    
    adj.assign(n+1, vi());
    vis.assign(n+1, false);
    tin.assign(n+1, 0);
    sub.assign(n+1, 0); // tam de cada sub tree
    low.assign(n+1, INF);
    edges.clear();
    
    
    int u, v; 
    while(m--){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    ans = 1e10;
    dfs(1);
    
    // for (auto t : tin) cout << t << " ";
    // cout << endl;
    // for (auto t : low) cout << t << " ";
    // cout << endl;

    // cout << edges.size() << endl;
    if (sz(edges) == 0 || ans == 1e10) ans = len_pair(n, 0);
    // for (auto [u, v] : edges) cout << u << " " << v << endl;

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento