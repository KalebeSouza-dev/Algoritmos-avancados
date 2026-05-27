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

string check(int n, auto& perm, int a, int b){
    string l = perm[a-1], r = perm[b-1];
    int aa = 0, bb = n;
    rep(i, 0, n){
        if (l[i] == r[i]){
            aa++; bb--;
        }
    }
    return to_string(aa) + 'A' + to_string(bb) + 'B';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    vector<string> perm2, perm3, perm4;
    string p2 = "12", p3 = "123", p4 = "1234";

    do {
        perm2.pb(p2);
    } while(next_permutation(all(p2)));
    do {
        perm3.pb(p3);
    } while(next_permutation(all(p3)));
    do {
        perm4.pb(p4);
    } while(next_permutation(all(p4)));

    // for(auto c : perm4) cout << c << endl;

    while(tc--){
        string n; int j, k; cin >> n >> j >> k;
        if (sz(n) == 2) cout << check(sz(n), perm2, j, k) << endl;
        else if (sz(n) == 3) cout << check(sz(n), perm3, j, k) << endl;
        else cout << check(sz(n), perm4, j, k) << endl;
    }
    
    return 0;
}

//maldito talento