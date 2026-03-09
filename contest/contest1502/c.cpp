#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int cont = 0;
    for (int i=0; i < n - 1; i++){
        if (arr[i] == 7 - arr[i+1] || arr[i] ==arr[i+1]){
            cont++;
            i++;
        }
    }
    cout << cont << endl;


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}