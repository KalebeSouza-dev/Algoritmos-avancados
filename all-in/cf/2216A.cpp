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
    int n, k; cin >> n >> k;
    vi b(k), a(n); 

    int curr = 0;
    rep(i, 0, k) cin >> b[i];
    
    vi out(n);
    rep(i, 0, n) {
        cin >> a[i];
        
        int abss = (k+1 - a[i]); 
        curr += abss;
        out[i] = abss;
    }
    sort(all(a));
    
    if (curr <= 1000){
        cout << curr << endl;
        for (int i = n-1; i >= 0; i--){
            rep(j, 0, out[i]){
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento