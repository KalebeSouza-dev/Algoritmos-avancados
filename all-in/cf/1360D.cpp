#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).rbegin(), (x).rend()
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
    int n, k; cin >> n >> k;
    if (k >= n) cout << 1 << endl;
    else {
        vector<int> div;
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0) {
                div.pb(i); 
                if (i * i != n) div.pb(n/i);
            }
        }
        sort(all(div));
        for (auto x : div){
            //cout << x << " ";
            if (k >= x){
                cout << n / x << endl; 
                return;
            }
        }

        cout << n << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}