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
    int n; cin >> n;
    if (1 < n  && n < 4){
        cout << "NO SOLUTION" << endl;
    } else {
        int f = n - 1;
        for (int i = f; i > 0; i -= 2){
            cout << i << " ";
        }
        for (int i = n; i > 0; i -= 2){
            cout << i << " ";
        }
        
    }
    cout << endl;
    //int t; cin >> t;
    //while(t--) solve_tc();
    
    return 0;
}