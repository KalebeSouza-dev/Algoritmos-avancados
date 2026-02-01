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
    vector<int> arr(n - 1);
    for (int i =0; i < n - 1; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (arr[n-2] != n) {
        cout << n << endl;
    } else if (arr[0] != 1) {
        cout << 1 << endl;
    } else {
        for(int i = 0; i < n - 2; i++){
            if (arr[i] + 1 != arr[i+1]){
                cout << arr[i] + 1 << endl;
                break;
            } 
        }
    }
    //int t; cin >> t;
    //while(t--) solve_tc();
    
    return 0;
}