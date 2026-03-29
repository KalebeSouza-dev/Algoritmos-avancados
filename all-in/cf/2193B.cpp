#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    vector<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];

    vector<ll> arr2 = arr;
    sort(all(arr2));
    ll idx = 0, l = 0;

    // rep(i, 0, n) cout << arr[i] << " ";
    // cout << endl;
    
    while (idx < n){
        //cout << arr[l] << " " << arr2[idx] << endl;
        if (arr[l] == arr2[idx]){
            idx++; l++;
        } else {
            for (ll i = l; i < n; i++){
                if (arr[i] == arr2[idx]) {
                    reverse(arr.begin() + l, arr.begin() + i + 1); 
                    break;}
            }
            break;
        }
            
    }

    rep(i, 0, n) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}