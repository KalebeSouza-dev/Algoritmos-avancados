#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    ll k, x; cin >> k >> x;

    vector<int> ops;

    ll start = 1LL << k;

    while(x != start){
        if(x > start){
            ops.push_back(2);
            x = 2*(x - start);
        }else{
            ops.push_back(1);
            x = 2*x;
        }
    }

    reverse(all(ops));

    cout << ops.size() << "\n";
    for(int o: ops) cout << o << " ";
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}