#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

void solve_tc(){
    int n; cin >> n;
    for (int i = 1; i <= n; i ++){
        cout << i << " ";
    }
    cout << endl;
}

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int t; cin >> t;
    while(t--) solve_tc();
    
    return 0;
}