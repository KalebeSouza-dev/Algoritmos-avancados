#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >>n>>m>>k;
    
    vector<int> pessoas(n);
    vector<int> ap(m);
    for (int i = 0; i < n; i++) cin >> pessoas[i];
    for (int i = 0; i < m; i++) cin >> ap[i];
    int cont = 0;

    sort(ap.begin(), ap.end());
    sort(pessoas.begin(), pessoas.end());

    int i = 0, j = 0;
    while (i < n && j < m){
        if (pessoas[i] - k <= ap[j] && pessoas[i] + k >= ap[j]){
            cont ++; i ++; j ++;
        } else if (pessoas[i] - k > ap[j]){
            j++;
        } else {
            i++;
        }
    }
    cout << cont << endl;
    
    return 0;
}