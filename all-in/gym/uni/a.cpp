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

    ll s, a, b, c; cin >> s >> a >> b >> c;
    
    if (s >= (a + b + c)) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}

//maldito talento