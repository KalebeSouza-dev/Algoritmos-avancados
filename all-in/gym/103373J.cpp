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
    string x, y; cin >> x >> y;

    for(auto c : x){
        if (isalpha(c)) {
            cout << "NaN" << endl;
            return;
        }
    }
    for(auto c : y){
        if (isalpha(c)) {
            cout << "NaN" << endl;
            return;
        }
    }
    int xx = stoi(x);
    int yy = stoi(y);

    
    cout << xx - yy << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; 
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento