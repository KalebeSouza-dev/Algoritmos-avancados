#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 100;
const ll INF = 1e12;
const int MOD = 1e9 + 7;

ll exp(ll n, ll k, ll MOD){
    ll ans = 1;
    n %= MOD;
    while(k > 0){
        if (k & 1) ans = (ans * n) % MOD;

        n = (n * n) % MOD;
        k >>= 1;
    }
    return ans;
}
void solve_tc(){
    int n, k; cin >> n >> k;
    cout << exp(n, k, MOD) << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int t; cin >> t;
    while(t--) solve_tc();
    
    return 0;
}