#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    
    for (int i = 0; i < n-1; i++){
        ll menor = 0, maior = 0;
        for (int j = i+1; j < n; j++){
            if(arr[j] > arr[i]) maior++;
            if(arr[j] < arr[i]) menor++;
        }
        cout << max(menor, maior) << " ";
    }

    cout << 0 << endl;
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}