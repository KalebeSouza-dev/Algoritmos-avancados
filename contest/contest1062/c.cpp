#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()
#define print(x) cout << ((x) ? "YES" : "NO") << "\n"

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(n);
    bool par = false, impar = false;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] % 2) par = true;
        else impar = true;
    }

    if(par && impar) sort(all(arr));

    for(int x : arr)
        cout << x << " ";
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int t; cin >> t;
    while(t--) solve_tc();
    
    return 0;
}