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
    int n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
    
    if (n <= 3) {
        cout << 1 << endl;
        return;
    }

    int ans = k;

    int mn;
    if (x2 > x1){
        mn = n - x2 + x1;
    } else {
        mn = n - x1 + x2;
    }
    ans += min(abs(x2-x1), mn);

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento