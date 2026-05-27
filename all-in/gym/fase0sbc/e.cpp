#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;

vi get_div(ll num){
    vi out;

    for(ll i = 1; i * i < num+1; i++){
        if (num % i == 0){
            out.pb(i);
            if(i * i != num) out.pb(num / i);
        }
    }

    return out;
}

int main() {
    ll y, k; cin >> y >> k;
    ll x = 1, i = 0;

    vi div = get_div(y);
    sort(all(div));
    vi clean = {1};
    for (int i = 1; i < sz(div); i++){
        if (div[i] % clean.back() == 0) clean.pb(div[i]);
    }

    // for (auto d : div) cout << d << " ";
    // cout << endl;

    ll a = k;
    //voltei pro cod1
    for (int i = 1; i < sz(clean); i++){
        ll resta = clean[i] / clean[i-1] - 1;
        if (a <= resta){
            x += a * clean[i-1];
            a = 0;
            break;
        }
        a -= resta;
        x += resta * clean[i-1];
    }
    if (a > 0) x += a * y;
    cout << x << endl;

    // ll a = k;
    // for (int i = 1; i < sz(clean); i++){
    //     a -= (clean[i] / clean[i-1] - 1);
    //     //cout << clean[i] << " " << clean[i-1] << " " << (clean[i] / clean[i-1]) << endl;
    // }
 
    // ll out = y + (a * y);
    // cout << out << endl;
 
    return 0;
}

//maldito talento