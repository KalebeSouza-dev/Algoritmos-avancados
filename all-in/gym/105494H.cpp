#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<vi> adj;
vector<bool> vis;
int cont = 0;

int dfs(int u, int p){
    cont++;
    vis[u] = true;

    for(auto v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
    }

    return cont;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    adj.assign(n+1, vi());
    vis.assign(n+1, false);
    vi arr(n+1);

    rep(i, 1, n+1){
        cin >> arr[i];
        adj[i].pb(arr[i]);
        adj[arr[i]].pb(i);
    }

    vector<pii> out;
    rep(i, 1, n+1){

        if (arr[i] == 0){
            cont = 0;
            int num = dfs(i, 0);
            out.pb({num, i});
        }
    }

    sort(all(out));
    cout << out[0].second << " " << out[0].first << endl;

    // cout << endl;
    // for(auto [u, v]: out) cout << u << " " << v << endl;

    return 0;
}

//maldito talento