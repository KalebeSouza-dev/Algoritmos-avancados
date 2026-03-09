#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    ll p, q; cin >> p >> q;

    if (p >= q) cout << "Alice\n";
    else {
        ll d = q - p;
        if (2 * d <= p)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}