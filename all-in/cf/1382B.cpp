#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "First\n"; }
inline void j2() { cout << "Second\n"; }

void solve_tc(){
    int n; cin >> n;
    
    vi arr(n); rep(i, 0, n) {
        cin >> arr[i];
    }
    
    ll cnt1 = 0;
    while (cnt1 < n && arr[cnt1] == 1) cnt1++;

    if(cnt1 == n){
        if (n % 2) j1();
        else j2();
    } else {
        if (cnt1 % 2) j2();
        else j1();
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

