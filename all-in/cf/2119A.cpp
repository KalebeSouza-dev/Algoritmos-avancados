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
    int a, b, x, y; cin >> a >> b >> x >> y;

    if ((a > b) && ((a^1) != b)) cout << -1 << endl;
    else {
        if (a > b) cout << y << endl;
        else {
            ll ans = 0;
           while(a != b){
            if (a % 2 == 0) ans += min(x, y);
            else ans += x; 
            a++;
           }
           cout << ans << endl;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}