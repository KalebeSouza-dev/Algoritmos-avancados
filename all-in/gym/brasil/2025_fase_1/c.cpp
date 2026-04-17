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

    int n, x; cin >> n;
    ll p = 0;
    
    for (int i = n; i >= 0; i--) {
        cin >> x;
        if (x) p |= (1LL << i);
    }
    
    int ans = 0;
    while (p != 1) {
        // se == 2, apaga: o xor resolve isso
        if (p & 1) {
            // se tiver K, * (x + 1) e + 1
            p = p ^ (p << 1);
            p ^= 1;
        } else {
            // se nao tiver K, / x;
            p >>= 1;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}
