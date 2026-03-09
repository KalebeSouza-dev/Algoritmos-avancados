#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(n + 1);
    for(int i=0; i < n; ++i) {
        int x; cin >> x;
        arr[x] = i;
    }

    int l = (n + 1) / 2;
    int r = (n + 2) / 2;

    while(l > 0){
        if(l == r || arr[l] < arr[l + 1] && arr[r - 1] < arr[r]){
            --l;
            ++r;
        }
        else break;
    }
    
    
    cout << (n - r + l + 1) / 2 << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}