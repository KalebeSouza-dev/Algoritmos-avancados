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
    ll t, h, u; cin >> t >> h >> u;
    ll ans = 0;

    ll mm = min(t, u);
    ans += mm * 4;
    t -= mm;
    u -= mm;
    ans += u * 3;

    mm = min(h, t/2);
    ans += mm * 7; h -= mm; t -= mm*2;

    if (h && t) {
        ans += 5;
        t -= 1; h -= 1;
    }

    if (t) ans += 3 * t - (t-1);
    
    if (h) ans += 3 * h;
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}