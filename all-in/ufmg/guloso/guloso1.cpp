#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int x, n, m; cin >> x >> n >> m;

    while (n--){
        if (x <= 20) break;
        x = x / 2 + 10;
    }
    while (m--){
        x -= 10;
    }
    if (x > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}