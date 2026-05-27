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

    int n; cin >> n;
    
    if (n % 3 == 1) cout << "Esteche\n";
    else cout << "Yvens\n";

    // int n; cin >> n;
    // vector<bool> dp(max(3,n+1), false); 
    
    // dp[0] = false;
    // dp[1] = false;
    // dp[2] = true;

    // for (int i = 3; i <= n; i++){
    //     if (!dp[i - 1]) dp[i] = true;
    //     if (!dp[i-2]) dp[i] = true;
    // }

    // if (dp[n]) cout << "Yvens\n";
    // else cout << "Esteche\n";

    return 0;
}