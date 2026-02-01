#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define pb push_back
#define endl "\n"
#define tii tuple<int,int,int>

const ll MAXN = 1e5 + 1000, INF = 1e18;
vector<vector<pair<int,int>>> grafo(MAXN);

void solve(int n){
    vector<vector<ll>> dist(MAXN, vector<ll>(2, INF));
    dist[1][0] = 0;

    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0, 1, 0});

    while(!pq.empty()){
        auto topo = pq.top();

        ll d = get<0>(topo);
        ll u = get<1>(topo);
        ll cupom = get<2>(topo);
        pq.pop();

        if(dist[u][cupom] < d) 
            continue;

        for(auto edge : grafo[u]){
            int v = edge.first;
            ll w = edge.second;

            if(dist[v][cupom] > d+w){
                dist[v][cupom] = d+w; 
                pq.push({d+w, v, cupom});
            }
            if(cupom==0 && dist[v][1] > d+w/2){
                dist[v][1] = d+w/2;
                pq.push({d+w/2, v, 1});
            }
        }
    }

    ll out = min(dist[n][0], dist[n][1]);
    cout << out << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        grafo[u].pb({v, w});
    }
    
    solve(n);
    return 0;
}