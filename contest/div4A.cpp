#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

void solve_tc(){
    int a,b,c; cin>>a>>b>>c;
    if (a == b) cout << c << endl;
    else if (c == b) cout << a << endl;
    else cout << b << endl;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}