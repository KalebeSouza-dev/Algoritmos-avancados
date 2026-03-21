#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ll odds = 0, soma = 0;
    bool temPar = false, temImpar = false;
    
    for(int i = 0; i < n; i++){
        soma += a[i];

        if(a[i] % 2 == 0) temPar = true;
        else { 
            temImpar = true; 
            odds++; 
        }
    }
    
    if(temPar && temImpar) cout << soma - (odds - 1) << endl;
    else cout << *max_element(all(a)) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}