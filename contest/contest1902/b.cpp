//UPSOLVE

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    for (int i = 1; i < n; i++){
        if (freq[i] > 2){
            freq[i+1] += freq[i] - 2;
            freq[i] = 2;
        }
    }
    //for (auto x : freq) cout << x << " ";
    //cout << endl;
    for (auto x : freq){
        if (x % 2 == 1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}