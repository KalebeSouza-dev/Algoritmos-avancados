#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;

    vector<ll> arr(n), lll, rr;
    vector<ll> prefixSum(n);
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        sum += arr[i];
        prefixSum[i] = sum;
    }

    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') lll.push_back(i);
        else rr.push_back(i);
    }

    //for (auto x : prefixSum) cout << x << " ";
    //cout << endl;

    ll out = 0;
    ll l = 0, r = rr.size()-1;
    while(l < lll.size() && r >= 0 && lll[l] < rr[r]){
        if (lll[l] < rr[r]){
            if (lll[l] == 0) {
                out+= prefixSum[rr[r]];
                //cout << "SOMA" << lll[l] << rr[r] << " " << prefixSum[rr[r]] << endl;
            } else {
                out+= prefixSum[rr[r]] - prefixSum[lll[l]-1];
                //cout << "SOMA" << lll[l] << rr[r] << " " << prefixSum[rr[r]] - prefixSum[lll[l]-1]<< endl;
            }
        } else break;
        l++; r--;
    }

    cout << out << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}