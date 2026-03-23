#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int t; cin >> t;
    ll out = 0;

    bool pos = false, neg = false;
    ll p = 0, n = 0;

    for (int i = 0; i < t; i++) {
        ll x; cin >> x;
        if (x > 0){
            if (pos){
                p = max(p, x);
            } else {
                p = x;
                out += n; n = 0;
                pos = true;
                neg = false;
            }
            //cout << "p" << p << endl;
        } else {
            if (neg){
                n = max(n, x);
            } else {
                n = x;
                out += p; p = 0;
                pos = false;
                neg = true;
            }
            //cout << "n" << n << endl;
        }
        
    };
    out += n + p;
    cout << out << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}