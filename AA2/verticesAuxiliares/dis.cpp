#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define tii tuple<ll,int,int>
#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 100;
const ll INF = 1e18;

int n, m;

vector<vector<pii>> adj;

vector<ll> dijkstra(int raiz, int n){
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF)); //cria a lista de dist com td INF index 1
    priority_queue<tii, vector<tii>, greater<tii>> pq;

    dist[raiz][0] = 0; // inicia a list pela raiz e adiciona na fila
    pq.push({0, raiz, 0});

    while(!pq.empty()){
        auto[distU, u, cupom] = pq.top();
        pq.pop();

        if(distU > dist[u][cupom]) continue; //distU é maior doq a menor dist já conhecida

        for(auto [v, w] : adj[u]){ // todos os vertices adj de u
            if( distU + w < dist[v][cupom]){ // pega a menor adj até o momento e joga na fila 
                dist[v][cupom] = distU + w;
                pq.push({distU + w, v, cupom});
            } if(cupom==0 && dist[v][1] > distU + w/2) {// usar o cupom
                dist[v][1] = distU+w/2;
                pq.push({distU +w/2, v, 1});
            }
        }
    }
    return dist[n];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    adj.resize(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        adj[u].pb({v, w});
    }
    vector<ll> out = dijkstra(1, n); 
    cout << min(out[0], out[1]) << endl;

    return 0;
}