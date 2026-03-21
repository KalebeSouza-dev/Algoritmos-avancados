#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


void solve_tc(){
    int n;cin >> n;
    vector<int> out(n);
 
    out[0] = out[1] = out[n - 1] = 1;
 
    for(int i = 2; i < n - 1; i++) out[i] = i;
 
    for(int i = 0; i < n; i++) cout << out[i] << " ";

    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}