#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

bool check(int n, int k, ll x){
    return ((x - (x / n)) >= k);
}

void solve_tc(){
    int n, k; cin >> n >> k;
    // n = 3, 1 2 33 4 5 66  [x * (3 - 1)]

    ll l = 0, r = 2e18 + 100;
    ll ans = r;
    while(l <= r){
        ll mid = (l + r) / 2;
        if (check(n, k, mid)) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}