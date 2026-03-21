#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;

        set<int> v;
 
    for(int i = 0,k;i < n;i++) {
        cin >> k;v.insert(k);
    }
 
    int s = 0;
    for(auto i : v) {
        if(i - s == 1) {
            s++;
        } else {
            cout << ((s % 2) ? "Bob" : "Alice") << endl;
            return;
        }
    }
 
    cout << ((s % 2) ? "Alice" : "Bob") << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

ll calc(ll x) {
    if(x % 4 == 0) return x;
    else if(x % 4 == 1) return 1;
    else if(x % 4 == 2) return x + 1;
    return 0;
}
void solve_tc() {
    int n;cin >> n; vector<ll> stk;
    rep(i,0,n) {
        ll x,m;cin >> x >> m;
 
        stk.push_back(calc(x - 1) ^ calc(x + m - 1));
    }
    int xr = 0;
    for(auto y : stk) xr ^= y;
 
    if(xr) cout << "tolik" << endl;
    else cout << "bolik" << endl;
}