#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    vector<pair<int, bool>> arr(n);
    rep(i, 0, n) {
        cin >> arr[i].first;
        if (i % 2 == 1) arr[i].second = true;
    }
    sort(all(arr));
    for(int i = 0; i < n-1; i++){
        if (arr[i].second == arr[i+1].second) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}