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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k; cin >> n >> k;
    vi sum(n, 0), a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    sort(all(a)); sort(all(b));
    rep(i, 0, n) sum[i] = a[i]+b[i];

    int ans = 0;
    rep(i, 0, n){
        if (sum[i] <= k){
            k-=sum[i];
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

//maldito talento