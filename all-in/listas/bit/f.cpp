#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T> struct bit {
    int n;
    vector<T> a;
    bit(int n) : n(n), a(n + 1) {}
    void add(int pos, T x) {
        for (; pos <= n; pos += (pos & -pos)) a[pos] += x;
    }
    T query(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= (pos & -pos)) ans += a[pos];
        return ans;
    }
};

// if (a[i] < a[j] && b[i] > b[j]) inv++;

void solve_tc(){
    int n; cin >> n;
    vector<pii> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second;
    sort(all(v));

    vi b; for (auto [a, bb] : v) b.pb(bb);

    bit<int> bt(n);
    ll ans = 0;

    vi comp = b;
    sort(all(comp));

    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(all(comp), b[i]) - comp.begin() + 1;
        
        ans += bt.query(pos - 1);
        bt.add(pos, 1);
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento