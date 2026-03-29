#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        int low = lower_bound(all(arr), l) - arr.begin();
        int up = upper_bound(all(arr), r) - arr.begin();

        cout << up - low << " ";
    }

    cout << endl;

    return 0;
}
