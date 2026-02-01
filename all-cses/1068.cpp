#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

//void solve_tc(){}

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    cout << n << " ";
    while (n != 1){
        if (n % 2 == 0){
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n << " ";
    }
    cout << endl;
    //int t; cin >> t;
    //while(t--) solve_tc();
    
    return 0;
}