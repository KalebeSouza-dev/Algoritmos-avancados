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

const int MAX = 200005;

vector<int> g[MAX];

//@brunomaletta
//Topological Sort (Kahn's Algorithm)
vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);
	
	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&](int v) {
		vis[v] = 1;
		for (auto u : g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	if (!dag) ret.clear();	
	return ret;
}

void solve_tc(){
    int n; cin >> n;
    
    rep(i, 0, n) g[i].clear();

    rep(i, 0, n-1){
        int u, v; ll x, y; cin >> u >> v >> x >> y;
        u--;v--;

        if (x > y) {
            g[v].pb(u);
        } else if (y > x) {
            g[u].pb(v); 
        }
    }

    auto topo = topo_sort(n);
    vi ans(n);
    rep(i, 0, n) {
        ans[topo[i]] = i+1;
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento