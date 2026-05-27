#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool check(ll mid, ll t, vi &k){
    ll curr = 0, i = 0;
    while(curr < t && i < sz(k)){
        curr += mid / k[i];
        i++;
    }
    if (curr >= t) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, t; cin >> n >> t;
    vi k(n); rep(i, 0, n) cin >> k[i];

    ll l = 0, r = 1e18 + 100;
    ll ans = r;

    while (l <= r){
        ll mid = l + (r - l) / 2;
        if (check(mid, t, k)){
            r = mid - 1;
            ans = mid;
        } else {
            l = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}

//maldito talento