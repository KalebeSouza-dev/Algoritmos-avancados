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

    ll n, m; cin >> n >> m;

    ll mn = max<ll>(0LL, n - (2 * m * 1LL));

    ll k = 0;
    while(1LL * k * (k-1) / 2 < m) k++;

    ll mx = n - k;
    cout << mn << " " << mx;

    return 0;
}

//maldito talento