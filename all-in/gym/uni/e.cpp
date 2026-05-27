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

    int n, d; cin >> n >> d;
    vector<pii> prods(n);
    rep(i, 0, n){
        cin >> prods[i].first >> prods[i].second;
    }
    sort(all(prods));
    vector<ll> ilhas = {};


    //entendi o problema errado, o abs() < d, e nao os vizinhos
    // twopointers

    vector<ll> melhor(n);

    ll curr_sum = 0;
    int l = 0;

    rep(r, 0, n){
        curr_sum += prods[r].second;

        while(prods[r].first - prods[l].first > d){
            curr_sum -= prods[l].second;
            l++;
        }

        melhor[r] = curr_sum;
        if (r > 0) melhor[r] = max(melhor[r], melhor[r-1]);
    }

    ll ans = 0; l = 0; curr_sum = 0;

    rep(r, 0, n){
        curr_sum += prods[r].second;

        while(prods[r].first - prods[l].first > d){
            curr_sum -= prods[l].second;
            l++;
        }

        ll left_best = (l > 0 ? melhor[l-1] : 0);
        ans = max(ans, curr_sum + left_best);
    }

    // for(auto x: melhor){
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << ans << endl;

    return 0;
}

//maldito talento