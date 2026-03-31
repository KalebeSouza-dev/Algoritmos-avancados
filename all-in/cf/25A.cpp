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
inline void () { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

void solve_tc(){
    int n; cin >> n;
    vector<pii> par, impar;
    rep(i, 1, n+1) {
        int x; cin >> x;
        if (x % 2 == 1) impar.pb({x, i});
        else par.pb({x, i});
    }
    if (sz(par) == 1) cout << par[0].second << endl;
    else cout << impar[0].second << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; tc = 1;
    while(tc--) solve_tc();
    
    return 0;
}