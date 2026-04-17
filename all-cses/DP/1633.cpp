#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vi dp(n+1, 0), ld = {1,2,3,4,5,6};

    for (int i = 1; i < n+1; i++){
        for (auto d : ld){
            if (i - d >= 0)
              
        }
    }


    return 0;
}
