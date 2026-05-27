#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }

void solve_tc(){
    int n, k; cin >> n >> k;
    vi a(n), b(k);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, k) cin >> b[i];
    sort(all(a)); sort(all(b));
    
    int i = 0, r = n-1;
    ll curr = 0;
    while(i < k && r >= 0){
        int x = b[i];
        
        if (x == 1){r--;}
        else {
            for(int j = 0; j < x - 1 && r >= 0; j++){
                curr+=a[r];
                r--;
            }
            r--;
        }
        i++;
    }
    
    while (r>=0){
        curr += a[r];
        r--;
    }

    cout << curr << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento