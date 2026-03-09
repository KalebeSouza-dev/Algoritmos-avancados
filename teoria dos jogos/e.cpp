#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    ll a, b, n; cin >> a >> b >> n;
    vector<ll> at(n), life(n);
    
    for (int i = 0; i < n; i++) cin >> at[i];
    for (int i = 0; i < n; i++) cin >> life[i];

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll vezes = (life[i] + a - 1) / a;
        b -= at[i] * vezes;
        mx = max(mx, at[i]);
    }

    if (b + mx > 0) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}