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
    //cout << "CASE" <<endl;
    int x, y, z; cin >> x >> y >> z; vi arr = {x,y,z};
    sort(all(arr));
    ll k, c; cin >> k; c = k;
    
    ll ans = 0;

    rep(i, 1, x+1) rep(j, 1, y+1){
        if (k % (i * j) == 0 && z >= k / (i*j)){
            ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1));
        }
    }
    
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}