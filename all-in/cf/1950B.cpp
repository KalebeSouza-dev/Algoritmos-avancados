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

    for (int i = 0; i <  2*n; i+=2){
        if (i % 4 == 0){
            for (int j = 0; j < 2*n; j+=2){
                if (j % 4 == 0) cout << "##";
                else cout << "..";
            }
            cout << endl;
            for (int j = 0; j < 2*n; j+=2){
                if (j % 4 == 0) cout << "##";
                else cout << "..";
            }
            cout << endl;
        } else {
            for (int j = 0; j < 2*n; j+=2){
                if (j % 4 == 0) cout << "..";
                else cout << "##";
            }
            cout << endl;
            for (int j = 0; j < 2*n; j+=2){
                if (j % 4 == 0) cout << "..";
                else cout << "##";
            }
            cout << endl;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento