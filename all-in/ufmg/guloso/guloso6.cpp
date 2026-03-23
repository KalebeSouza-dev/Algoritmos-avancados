    #include "bits/stdc++.h"
    using namespace std;

    #define endl '\n'
    #define rep(i, a, b) for (int i = a; i < (b); i++)
    #define all(x) (x).begin(), (x).end()
    #define sz(x) (int)(x).size()
    typedef long long ll;

    int main() {
        cin.tie(0)->sync_with_stdio(0);
        
        int n; cin >> n;
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
        
        sort(all(arr));

        //for (auto x : arr) cout << x.first << " " << x.second << endl;

        ll out = 1;
        int last = arr[n -1].first;
        for (int i = n-2; i >= 0; i--){
            if (arr[i].second < last) {
                out++;
                last = arr[i].first;
            }
        }

        cout << out << endl;

        return 0;
    }
