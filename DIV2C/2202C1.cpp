#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    ll n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int c  = n;
    bool flag = false;
    pair<int,int> curr = {-1,-1};
    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i-1]+1) {
            c--;
            if(!flag) curr = {arr[i-1], arr[i]};
            else curr.second = max(curr.second, arr[i]);
            flag = true;
        } else if (flag && arr[i] == arr[i-1]){
            c--;
            if(!flag) curr.first = arr[i-1];
            else curr.second = max(curr.second, arr[i]);
            flag = true;  
        } else if (arr[i] > curr.first && arr[i] < curr.second){
            c--;
        }else {
            flag = false;
            curr = {-1,-1};
        }
    }
    cout << c << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}