#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()
#define print(x) cout << ((x) ? "YES" : "NO") << "\n"

void solve_tc(vector<ll> &p){
    int n; cin >> n;
    ll g = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        g = __gcd(g, x); 
    }

    if (g == 1) cout << 2 << endl;
    else if (g == 2) cout << 3 << endl;
    else {
        for (ll a : p){
            if (g % a != 0){
                cout << a << endl;
                return;
            }
        }
    }
}
bool isPrime(ll x){
    if(x < 2) return false;
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}
vector<ll> prime(){
    vector<ll> out;
    out.push_back(2);
    for (int i = 3; i < 99; i++){
        if (isPrime(i)) out.push_back(i);
    }
    return out;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    vector<ll> primes = prime();

    int t; cin >> t;
    while(t--) solve_tc(primes);
    
    return 0;
}