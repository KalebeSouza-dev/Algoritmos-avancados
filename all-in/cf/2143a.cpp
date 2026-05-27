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
    int n; cin >> n;

    int iMax = -1;
    vi arr(n+1); rep(i, 1, n+1){
        cin >> arr[i];
        if (arr[i] == n) iMax = i; 
    }

    int l = iMax-1, r = iMax+1;
    int curr = n;
    while(curr > 1){
        if(l>0 && arr[l] == curr-1){
            l--; curr--;
        } else if (r <= n && arr[r] == curr-1){
            r++; curr--;
        } else {
            no(); return;
        }
    }

    yes();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento