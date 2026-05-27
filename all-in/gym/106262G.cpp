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

const ll INF = 10e10;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, b; cin >> n >> b;
    ll best = -INF;

    bool eh = false;

    ll ans = b;
    vi arr(n-1); rep(i, 0, n-1) {
        cin >> arr[i];

        if (arr[i] > 0) {
            ans += arr[i];
            eh = true;
        }
    }

    if (eh){
        cout << ans << endl;
        return 0;
    }
    
    for (auto x : arr){
        if (b + x >= 0) best = max<ll>(best, b+x);
    }

    if (best == -INF) cout << -1 << endl;
    else cout << best << endl;

    return 0;
}

//maldito talento