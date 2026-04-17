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
    vi out;

    ll mult = 1;
    for (int i = arr[2]; i>=1; i--){
        if (k % i == 0) {
            k /= i;
            out.pb(i);
            mult *= i;
            break;
        }
    }
    for (int i = arr[1]; i>=1; i--){
        if (k % i == 0) {
            k /= i;
            out.pb(i);
            mult *= i;
            break;
        }
    }
    for (int i = arr[0]; i>=1; i--){
        if (k % i == 0) {
            k /= i;
            out.pb(i);
            mult *= i;
            break;
        }
    }
    
    if (mult != c) cout << 0 << endl;
    else {
        sort(all(out));

        //faltou chegar nesse +1 da fórmula
        ll ans = (arr[0] - out[0] + 1);
        ans *= (arr[1] - out[1] + 1);
        ans *= (arr[2] - out[2] + 1);

        // for(auto x : arr) cout << x << " ";
        // cout << endl;

        // for(auto x : out) cout << x << " ";
        // cout << endl;

        cout << ans << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}