#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    vector<int> freq(n*n+1, 0);
    int x;
    rep (i, 0, n) {
        rep(j, 0, n) {
            cin >> x;
            freq[x]++;
        }
    }
    for (auto x : freq) {
        if (x > (n*n-n)) {cout << "NO\n"; return;}
    }
    cout << "YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}