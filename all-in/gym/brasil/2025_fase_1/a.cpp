#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    vector<vi> arr(m);
    int x;
    while(n--){
        rep(i, 0, m){
            cin >> x;
            arr[i].pb(x);
        }
    }
    ll mx = 0;
    for (auto b : arr){
        sort(all(b));
        mx += b[0];
    }

    cout << mx << endl;

    return 0;
}
