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

    int n; cin >> n;

    vector<pii> temp;
    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        temp.pb({x, 1});
        temp.pb({y, -1});
    }
    sort(all(temp));
    
    ll ans = 0, curr =0;
    for(auto [x, y] : temp){
        curr += y;
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}

//maldito talento