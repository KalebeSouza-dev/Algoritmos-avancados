#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int x, y; cin >> x >> y;

    ll a = 0;
    if(y > 0) a = y*2;
    else if(y < 0) a = -y*4;

    if(x >= a && (x - a) % 3 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}