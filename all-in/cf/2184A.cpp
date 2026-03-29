#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    if (n == 2) cout << 2 << endl;
    else if (n == 3) cout << 3 << endl;
    else if (n % 6 == 0) cout << 0 << endl;
    else if (n % 2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}