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


    int n, m, p, s; cin >> n >> m >> p >> s;
    int qing = n - p - s;

    vector<pii> proibidos(m);
    rep(i, 0, m){
        ll x, y; cin >> x >> y;
        y--; x--;
        proibidos[i].first = x;
        proibidos[i].second = y;
    }

    ll ans = 0;

    rep(pao, 0, p){
        rep(sal, p, p+s){
            pii p1 = {pao, sal}, p2 = {sal, pao};
            if (count(all(proibidos), p1) || count(all(proibidos), p2)) continue;

            
            rep(mask, 0, (1 << qing)){
                vi conj = {pao, sal};
                rep(i, 0, qing){
                    if (mask & (1<<i)){
                        conj.pb(p + s + i);
                    }
                }
                bool eh = true;
                for (auto [x, y] : proibidos){
                    if(count(all(conj), x) && count(all(conj), y)) {
                        eh = false;
                        break;
                    }
                }
                // if (eh) cout << "valid ";
                // for (auto c: conj) cout << c << " ";
                // cout << endl;
                if (eh) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

//maldito talento