#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n, h, l; cin >> n >> h >> l;
    vector<int> arr(n), mH, mL;
    rep(i, 0, n) {
        cin >> arr[i];
        if (arr[i] <= h) mH.push_back(arr[i]);
        if (arr[i] <= l) mL.push_back(arr[i]);
    }
    sort(all(mH)); sort(all(mL));
    int ll = (int)mL.size();
    int hh = (int)mH.size();

    int ans =0;
    if (hh >= ll){
        int diff = hh - ll;
        if (diff >= ll) cout << ll << endl;
        else cout << diff + (ll - diff) / 2 << endl;
    } else {
        int diff = ll - hh;
        if (diff >= hh) cout << hh << endl;
        else cout << diff + (hh - diff) / 2 << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}