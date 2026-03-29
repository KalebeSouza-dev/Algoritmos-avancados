    #include "bits/stdc++.h"
    using namespace std;

    #define endl '\n'
    #define rep(i, a, b) for (int i = a; i < (b); i++)
    #define all(x) (x).begin(), (x).end()
    #define sz(x) (int)(x).size()
    typedef long long ll;

    int main() {
        cin.tie(0)->sync_with_stdio(0);
        
        int n, kk; cin >> n >> kk;
        vector<int> arr(n), karr(kk); 

        rep(i, 0, n) cin >> arr[i];
        rep(i, 0, kk) cin >> karr[i];

        for (auto x : karr){
            int l = 0, r = n -1;

            int out = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                
                if (arr[mid] <= x) {
                    l = mid + 1;
                    out = mid+1;
                } else {
                    r = mid - 1;
                }
            }
            cout << out << endl;
        }
        return 0;
    }
