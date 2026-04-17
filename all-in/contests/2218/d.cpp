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

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

void solve_tc(vi& primos){
    int n; cin >> n;

    // i * (i -1)
    // 1*2 2*3 3*4 4*5 5*6
    // 1 2 6 12 20 30
    // 1 2 6 4 10

    cout << 1 << " ";
    for(int i = 1; i < n; i++){
        cout << 1LL * primos[i-1] * primos[i] << " ";
    }

    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    //crivo
    const int MAX = 212345;
    vector<int> primes;
    vector<bool> is_prime(MAX, true);

    for(int i = 2; i < MAX; i++){
        if(is_prime[i]){
            primes.pb(i);
            for(ll j = 1LL * i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }

    int tc = 1; cin >> tc;
    while(tc--) solve_tc(primes);
    
    return 0;
}