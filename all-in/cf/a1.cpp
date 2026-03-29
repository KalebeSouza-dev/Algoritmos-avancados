#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    long double n, m, a; cin >> n >> m >> a;

    ll out = (ll) ceil(n/a) * (ll) ceil(m/a);
    cout << out << endl;


    return 0;
}
