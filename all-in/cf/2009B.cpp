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
    int n; vector<int> arr;
    cin >> n;
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, 4) {
            if (s[j] == '#') {
                arr.pb(j+1);
            }
        }
    }

    for (int i = n-1; i >= 0; i--){
        cout << arr[i] << " ";
    }
    cout << endl;   
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}