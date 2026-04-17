#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll lim, n; cin >> lim >> n;
    vector<ll> arr(n); rep(i, 0, n) cin >> arr[i];
    ll l = 0, r = lim;

    rep(i, 0, n){
        if (arr[i] >= 0){
            l = min(l + arr[i], lim);
            r = min(r + arr[i], lim);
        } else {
            l = max(l + arr[i], 1LL * 0);
            r = max(r + arr[i], 1LL * 0);
        }

    }

    if (l == r) cout << l << endl;
    else cout << "uncertain" << endl;

    return 0;
}
