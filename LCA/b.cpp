#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define pb push_back
const int MAXN = 1e5 + 10;
const int LOG = 20;

int n, m, q;
vector<int> grafo[MAXN];
int up[MAXN][LOG];
int prof[MAXN];

vector<int> best[MAXN][LOG];
vector<int> moradores[MAXN];

vector<int> merge10(vector<int> &a, vector<int> &b){
    vector<int> aux;
    aux.reserve(10);
 
    int i = 0, j = 0; 
    while(aux.size() < 10 && (i < a.size() || j < b.size())){
        if (j == b.size() || (i < a.size() && a[i] <= b[j])) aux.pb(a[i++]);
        else aux.pb(b[j++]);
    }
    return aux;
}
void dfs(int v, int p){
    up[v][0] = p;
    best[v][0] = moradores[v];

    for (int i = 1; i < LOG; ++i) {
        if (up[v][i-1] == -1) {
            up[v][i] = -1;
            best[v][i].clear();
        } else {
            up[v][i] = up[ up[v][i-1] ][i-1];
            if (up[v][i] == -1) best[v][i] = best[v][i-1];
            else best[v][i] = merge10(best[v][i-1], best[ up[v][i-1] ][i-1]);
        }
    }
    for (int to : grafo[v]) {
        if (to == p) continue;
        prof[to] = prof[v] + 1;
        dfs(to, v);
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
vector<int> pessoasCaminho(int v, int dist){
    vector<int> res;
    for (int i = LOG-1; i >= 0; --i) {
        if (dist & (1<<i)) {
            if (v == -1) break;
            res = merge10(res, best[v][i]);
            v = up[v][i];
        }
    }
    return res;
}
void solve_tc(){
    int v, u, a; cin >> v >> u >> a;
    int w = lca(v,u);

    vector<int> ans;
    if (prof[v] < prof[u]) swap(v, u);

    vector<int> t = pessoasCaminho(v, prof[v] - prof[w]);
    ans = merge10(ans, t);
    
    t = pessoasCaminho(u, prof[u] - prof[w]);
    ans = merge10(ans, t);
    
    ans = merge10(ans, moradores[w]);
    
    int k = min((int)ans.size(), a);
    cout << k;
    for (int i = 0; i < k; ++i) cout << " " << ans[i];
    cout << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m , q; cin >> n >> m >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        grafo[v].pb(u);
        grafo[u].pb(v);
    }
    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        moradores[k].pb(i);
    }
    for (int v = 1; v <= n; ++v){
        sort(moradores[v].begin(), moradores[v].end());
        if (moradores[v].size() > 10) moradores[v].resize(10);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < LOG; ++j)
            up[i][j] = -1;

    prof[1] = 0;
    dfs(1, -1);

    while (q--) solve_tc();

    return 0;
}