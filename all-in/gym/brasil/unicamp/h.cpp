#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;

    vi ans(m+1,-1);
    
    int len; cin >> len;
    set<int> prefix;
    vi arr(len); rep(i, 0, len) {
        cin >> arr[i];
        ans[arr[i]] = 0;
        prefix.insert(arr[i]);
    }

    int last = arr[len-1];
    // for (auto x: ans) cout << x << " ";
    // cout << endl;

    rep(i, 1, n){
        // cout << "ROUND" << i+1 << endl;
        bool eh_last = false;
        cin >> len; vi arr(len); 

        bool teve_last = false;
        rep(j, 0, len){
            cin >> arr[j];
            if (arr[j] == last) teve_last = true;
        }
        
        //cout << last << " " << teve_last << endl;
        if (!teve_last) {
            eh_last = true;
            last = arr[len-1];
        }
        rep(j, 0, len) {
            if (arr[j] == last) eh_last = true;
            // cout << arr[j] << " " << eh_last << endl;

            if ((!prefix.count(arr[j])) && (!eh_last)){
                // cout << arr[j] << "entrou" << endl;
                ans[arr[j]] = 1;
            }
            prefix.insert(arr[j]);
        }
        last = arr[len - 1];
    }

    for (int i = 1; i <= m; i++){
        cout << max(0, ans[i]) << " ";
    }
    cout << endl;

    return 0;
}