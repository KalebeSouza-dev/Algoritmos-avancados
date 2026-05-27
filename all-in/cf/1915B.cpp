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
    string s; rep(i, 0, 3){
        cin >> s;
        int a = 0, b = 0, c = 0;
        for (auto x : s){
            if(x == 'A') a++;
            if(x == 'B') b++;
            if(x == 'C') c++;
        }
        if (s[0] = '?'){
            if (c == 0) cout << 'C';
            if (b == 0) cout << 'B';
            if (a == 0) cout << 'A';
        } else if (s[1] = '?'){
            if (c == 0) cout << 'C';
            if (b == 0) cout << 'B';
            if (a == 0) cout << 'A';
        } else if (s[2] = '?'){
            if (c == 0) cout << 'C';
            if (b == 0) cout << 'B';
            if (a == 0) cout << 'A';
        }
    }
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento