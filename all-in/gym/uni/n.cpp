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

const int MAXN = 1e6 + 5;

vi div(ll n){
    vi div;
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0) {
            div.pb(i);
            if(i * i != n) div.pb(n/i);
        }
    }
    div.pb(n);
    sort(all(div));
    return div;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vi cont(MAXN, 0), freq(MAXN, 0);
    vector<bool> on(MAXN, false);

    int n; cin >> n;
    vector<int> arr(n); rep(i, 0, n){
        cin >> arr[i];
    }

    int ans = 0;
    rep(i, 0, n){
        auto divi = div(arr[i]);
        if(!on[arr[i]]){
            for(auto d : divi){
                if(cont[d] > 0) freq[cont[d]]--;
                cont[d]++;
                freq[cont[d]]++;
                ans = max(ans, cont[d]);
            }
        } else {
            for(auto d : divi){
                if(cont[d] > 0) freq[cont[d]]--;
                cont[d]--;
                if(cont[d] > 0) freq[cont[d]]++;
            }

            while(ans > 0 && freq[ans] == 0) ans--;            
        }
        
        on[arr[i]] = !on[arr[i]];

        cout << ans << endl;
    }
    return 0;
}

//maldito talento