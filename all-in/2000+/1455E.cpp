#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

#define x first
#define y second

//q: (a,b) e (c,d)
//r: (a,c) e (b,d)
//s: (a,d) e (b,c)

void solve_tc(){
    vector<pair<ll, ll>> p(4);
    rep(i, 0, 4) cin >> p[i].x >> p[i].y;

    ll ans = LLONG_MAX;

    rep(rot, 0, 2){
        rep(i, 0, 4) rep(j, 0, 4){
            ll x1 = p[i].x;
            ll x2 = p[j].x;
            if(x1 > x2) continue;

            ll side = abs(x1 - x2);

            rep(k, 0, 4){
                ll y1 = p[k].y;

                for(int sgn : {-1, 1}){
                    ll y2 = y1 + sgn * side;

                    vector<pair<ll,ll>> sq = {
                        {x1, y1},
                        {x2, y1},
                        {x2, y2},
                        {x1, y2}
                    };

                    sort(all(sq));

                    do{
                        ll cur = 0;
                        rep(t, 0, 4){
                            cur += abs(p[t].x - sq[t].x) + abs(p[t].y - sq[t].y);
                        }
                        ans = min(ans, cur);
                    }while(next_permutation(all(sq)));
                }
            }
        }

        // swap x e y
        for(auto &pt : p) swap(pt.x, pt.y);
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}