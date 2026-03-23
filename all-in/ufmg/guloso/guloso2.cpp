#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;

    int a = 0, b = 0;

    a += (1 << n); // 2^n
    for (int i = 1; i < n/2; i++) {
        a += (1 << i);
    }

    for (int i = n/2; i < n; i++) {
        b += (1 << i);
    }

    cout << abs(a - b) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}