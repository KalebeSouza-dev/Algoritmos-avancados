#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    ll n; cin >> n;
    
    bool ok = true;
    ll x = 1e9, y;
    for(ll i=0;i<n;i++){
        cin >> y;
        if(x*2 <= y) ok = false;
        x = min(x, y);
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}