#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

void solve_tc(){
    int n; cin >> n;
    int cont0 = 0, c1 = 0, x, c2 = 0;

    rep(i, 0, n){
        cin >> x;
        if(!x) cont0++;
        if (x==1) c1++;
        else if (x==2) c2++;
    }

    ll ans = min(c1, c2);
    c1-=ans;
    c2-=ans;
    ans+= cont0;

    ans+= c1/3;
    ans+= c2/3;

    cout << ans << endl; 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento