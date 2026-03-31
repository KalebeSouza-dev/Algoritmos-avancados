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

void solve_tc(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<int> g(n-1);
    for (int i = 0; i < n-1; i++){
        g[i] = __gcd(a[i], a[i+1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int need = 1;

        if (i > 0) need = g[i-1];
        if (i < n-1){
            if (need == 1) need = g[i];
            else need = (need / __gcd(need, g[i])) * g[i];
        }

        if (need < a[i]) ans++;
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}