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

    int w, h, d; cin >> w >> h >> d;
    int n; cin >> n;
    ll mult = (w*h*d);
    cout << mult << endl;
    if ((w*h*d) % n != 0) cout << -1 << endl;
    else {
        ll v = ((w*h*d) / n );

        ll x = gcd(w, n);
        n /= x;
        ll y = gcd(h, n);
        n /= y;
        ll z = gcd(d, n);

        cout << x-1 << " " << y-1 << " " << z-1 << endl;
    }

    return 0;
}