#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    string s; cin >> s;
    int um = count(all(s), '1');
    int zero = count(all(s), '0');
    if (min(um, zero) % 2 == 1) cout << "DA\n";
    else cout << "NET\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}