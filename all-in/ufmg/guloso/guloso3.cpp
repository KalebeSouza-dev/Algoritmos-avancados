#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    ll x, y, a, b; cin >> x >> y >> a >> b;

    ll out = 0;
    out += abs(x - y) * a;
    if (2*a < b){
        out += min(x, y) * a * 2;
    } else {
        out += min(x, y) * b;
    }

    cout << out << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}