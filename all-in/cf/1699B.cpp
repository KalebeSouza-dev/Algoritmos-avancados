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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));

    for(int i = 0; i < n; i += 2) {
        for(int j = 0; j < m; j += 2) {
            if(((i/2 + j/2) % 2) == 0) {
                a[i][j] = 1;
                a[i][j+1] = 0;
                a[i+1][j] = 0;
                a[i+1][j+1] = 1;
            } else {
                a[i][j] = 0;
                a[i][j+1] = 1;
                a[i+1][j] = 1;
                a[i+1][j+1] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}