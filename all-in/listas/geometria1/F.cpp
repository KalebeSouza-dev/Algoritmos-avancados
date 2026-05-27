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

    int t, r; cin >> t;
    // while(t--){
    //     cin >> r;

    //     ll lim_inf = r, lim_sup = r;
    //     const ll RR = 1LL *  r*r, RRR = 1LL * (r+1) * (r+1);
        
    //     ll out = 0;
    //     for (int i = 1; i <= r; i++){
    //         while(lim_inf >= 0 && 1LL * i * i + 1LL * lim_inf * lim_inf >= RR) lim_inf--;
    //         while(lim_sup >= 0 && 1LL * i * i + 1LL * lim_sup * lim_sup >= RRR) lim_sup--;
            
    //         //cout << i << " " << lim_sup * 4 << " " << lim_inf * 4 << endl;
    //         out += max(0LL, 1LL * (lim_sup - lim_inf));
    //     }
    //     cout << 4 * out << endl;
    // }

    // solucao lenta
    while(t--){
        cin >> r;
        int out = 0;
        for (int i = 0; i <= r; i++){
            for (int j = 0; j <= r; j++){
                if (i == j && i == 0) continue;

                ll sq = sqrt(1LL * i * i + 1LL * j * j);
                if (r <= sq && sq < r+1) out++;
            }
        }
        cout << out * 4 - 4 << endl;
    }
    
    return 0;
}