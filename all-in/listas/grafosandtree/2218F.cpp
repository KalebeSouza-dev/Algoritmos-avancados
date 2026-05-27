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

void solve_tc(){
    //cout << "CASE" << endl;
    int x, y; cin >> x >> y;

    int root = 1, v = 2, contP = 0, contI = 1;
    if (y == 0 || (x == 0 && y % 2 == 0) || x > y) no();
    else {
        yes();
        if (x == 0){
            while(contI < y){
                cout << 1 << " " << v++ << endl;
                contI++;
            }
        } else {
            while(contP < x){
                cout << root << " " << v << endl;
                if(contI < y) {
                    cout << v++ << " " << v++ << endl;
                    contI++;
                }

                contP++; 
            }
            while(contI < y){
                cout << 2 << " " << v++ << endl;
                contI++;
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

//maldito talento