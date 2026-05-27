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
    vector<string> arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }
    rep(i, 0, n){
        rep(j, 0, n){
            if (arr[i][j] == '1'){
                int lim = j;

                while (lim + 1 < n && arr[i][lim + 1] == '1'){
                    lim++;
                }

                if (lim - j == 1){
                    cout << "TRIANGLE" << endl;
                } else {
                    int len = lim - j + 1;

                    if (i + len - 1 < n &&
                        arr[i + len - 1][j] == '1' &&
                        arr[i + len - 1][lim] == '1'){
                        cout << "SQUARE" << endl;
                    } else {
                        cout << "TRIANGLE" << endl;
                    }
                }
                return;
            }
            
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}