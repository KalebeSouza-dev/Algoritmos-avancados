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
    int n, m; cin >> n >> m;
    vi x(n), r(n);
    
    map<int, ll> pts_x;

    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n) cin >> r[i];

    rep(i, 0, n){
        for(int j = x[i] - r[i]; j <= x[i] + r[i]; j++){
            ll h = sqrt(1LL * r[i]*r[i] - 1LL * (j - x[i])*(j - x[i]));
            pts_x[j] = max(pts_x[j], 2*h + 1);
        }
    }
    
    ll ans = 0;
    for (auto [k, v] : pts_x){
        ans += v;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}