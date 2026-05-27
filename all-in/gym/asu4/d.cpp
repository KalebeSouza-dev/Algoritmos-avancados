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

    int n, x; cin >> n >> x;
    vi arr(n); rep(i, 0, n) cin >> arr[i];

    ll mn = LLONG_MAX, curr = 0;
    for (int i = 0; i < n-1; i++){
        curr = arr[i];
        int cont = 1;
        if (curr >= x) {cout << 1 << endl; return 0;}

        for(int j = i+1; j < n; j++){
            if (curr < x) {
                curr += arr[j];
                cont++;
            } else break;
        }
        if (curr >= x) mn = min<ll>(mn, cont);
    }

    if (mn == LLONG_MAX) cout << -1 << endl;
    else cout << mn << endl;

    return 0;
}

//maldito talento