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
    vector<pii> a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    sort(all(a));

    rep(i, 0, n){
        if (a[i].first <= k) k+= a[i].second;
    }

    cout << k << endl;

    return 0;
}