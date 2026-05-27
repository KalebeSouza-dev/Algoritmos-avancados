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

// sos, apanhando pra qst facil
void solve_tc(){
    //cout << "CASE" << endl;
    int n; cin >> n;

    ll sum = 0; int mx = INT_MIN, mn = INT_MAX;
    vi arr(n); rep(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];

        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }        
    int positivo = 0;
    for (auto x : arr) if (x > 0) positivo++;

    
    cout << min<ll>(positivo, sum - n + 1) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento