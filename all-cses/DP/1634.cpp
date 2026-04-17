    #include "bits/stdc++.h"
    using namespace std;

    #define endl '\n'
    #define rep(i, a, b) for (int i = a; i < (b); i++)
    #define all(x) (x).begin(), (x).end()
    #define sz(x) (int)(x).size()
    typedef long long ll;

    int main() {
        cin.tie(0)->sync_with_stdio(0);
        
        int n, x; cin >> n >> x;
        vector<int> dp(x+1, 1123456), moedas(n);

        rep(i, 0, n) cin >> moedas[i];

        dp[0] = 0;
        for (int i = 1; i < x+1; i++){
            for (auto c : moedas){
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        
        // for (auto x : dp) cout << x << " ";
        // cout << endl;
        
        if (dp[x] == 1123456) cout << -1 << endl;
        else cout << dp[x] << endl; 

        return 0;
    }
