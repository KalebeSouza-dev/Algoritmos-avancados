#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k; cin >> n >> k;
    vector<int> arr(n), karr(k);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < k; i++) cin >> karr[i];

    for (auto kk : karr){
        // if (binary_search(all(arr), kk)) cout << "YES\n";
        // else cout << "NO\n";
        
        int l = 0, r = n-1;
        bool eh = false;
        while(r >= l){
            int mid = (l + r) / 2;
            if (arr[mid] == kk){
                eh = true;
                break;
            }
            if (arr[mid] > kk){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (eh) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
