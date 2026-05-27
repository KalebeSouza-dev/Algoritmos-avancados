#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }

ll dis(int x1, int y1, int x2, int y2) {
    return 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1);
}

void solve_tc(){
    int n; cin >> n;
    
    vector<pii> pts(n);
    rep(i, 0, n) {
        cin >> pts[i].first >> pts[i].second;
    }
    sort(all(pts));

    pii start, end; cin >> start.first >> start.second >> end.first >> end.second;

    for (auto [x, y] : pts){
        if (dis(x, y, end.first, end.second) <= dis(start.first, start.second, end.first, end.second)){
            no();
            return;
        }
    }

    yes();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}