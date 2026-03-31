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
    string r; cin >> r; int n; n = sz(r);

    int ans = 0;
    if (r[0] == 'u') {r[0] = 's'; ans++;}
    if (r[n-1] == 'u') {r[n-1] = 's'; ans++;}

    for (int i = 1; i < n-1; i++){
        if (r[i] == 'u'){
            if (r[i-1] == 'u') ans++;
            if (r[i+1] == 'u') {r[i+1] = 's'; ans++;}
        }
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}