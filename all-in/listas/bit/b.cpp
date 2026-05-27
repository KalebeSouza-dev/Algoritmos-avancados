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

template<typename T> struct bit {
    int n;
    vector<T> a;
    bit(int n) : n(n), a(n + 1) {}
    void add(int pos, T x) {
        for (; pos <= n; pos += (pos & -pos)) a[pos] += x;
    }
    void set(int pos, T x){
        ll curr = query(pos, pos);
        ll delta = x - curr;
        add(pos, delta);
    }
    T query(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= (pos & -pos)) ans += a[pos];
        return ans;
    }
    T query(int l, int r) {
        return query(r) - query(l-1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q; cin >> n >> q;
    bit<ll> bt(n+1);
    int x; rep(i, 0, n){
        cin >> x;
        bt.add(i+1, x);
    }
    
    while(q--){
        int k, a, b; cin >> k >> a >> b;
        if (k == 2){
            cout << bt.query(a, b) << endl;
        } else {
            bt.set(a+1, b);
        }
    }

    return 0;
}