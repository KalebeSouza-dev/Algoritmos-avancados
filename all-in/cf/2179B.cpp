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
    // cout << endl << "CASE" << endl;

    int n; cin >> n;
    vi arr(n), b(n-1);
    rep(i, 0, n) cin >> arr[i];
    ll sum = 0;
    rep(i, 0, n-1) {b[i] = abs(arr[i] - arr[i+1]); sum += b[i];}

    ll ans = min(sum - abs(arr[1] - arr[0]), sum - abs(arr[n-1] - arr[n-2]));

    rep(i, 1, n-1) {
        ans = min(ans, sum + abs(arr[i-1] - arr[i+1]) - abs(arr[i-1] - arr[i]) - abs(arr[i] - arr[i+1]));
    }

    cout << ans << endl;

    // for (auto x : b) cout << x << " ";
    // cout << endl; 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}