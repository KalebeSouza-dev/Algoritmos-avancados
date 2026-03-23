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

ll ans(auto x0, auto x1, auto x2, auto x3){
    ll q = abs(x0.x - x1.x) + abs(x2.x - x3.x);
    q += min(abs(x0.y - x2.y) + abs(x1.y - x3.y),
            abs(x0.y - x3.y) + abs(x1.y - x2.y));

    ll r = abs(x0.x - x2.x) + abs(x1.x - x3.x);
    r += min(abs(x0.y - x1.y) + abs(x2.y - x3.y),
            abs(x0.y - x3.y) + abs(x1.y - x2.y));

    ll s = abs(x0.x - x3.x) + abs(x1.x - x2.x);
    s += min(abs(x0.y - x2.y) + abs(x1.y - x3.y),
            abs(x0.y - x1.y) + abs(x2.y - x3.y));

    return min({q, r, s});
}

void solve_tc(){
    pair<int, int> a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    vector<pair<int, int>> pts = {a, b, c, d};

    vector<int> ord_x = {a.x, b.x, c.x, d.x};
    sort(all(ord_x));
    ll cost_x = (ord_x[1] - ord_x[0]) + (ord_x[3] - ord_x[2]);

    vector<int> ord_y = {a.y, b.y, c.y, d.y};
    sort(all(ord_y));
    ll cost_y = (ord_y[1] - ord_y[0]) + (ord_y[3] - ord_y[2]);

    cout << cost_x + cost_y << endl;
    cout << ans(a, b, c, d) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}