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
    T query(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= (pos & -pos)) ans += a[pos];
        return ans;
    }
    T query(int l, int r) {
        return query(r) - query(l);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q; cin >> n >> q;
    
    bit<ll> bt(n+1);
    
    vi arr(n+1); rep(i, 1, n+1) {
        cin >> arr[i];
        bt.add(i, arr[i]);
    }

    while(q--){
        int k; cin >> k;

        if (k == 1){
            int l, r; cin >> l >> r;
            cout << bt.query(l, r) << endl;
        } else {
            int pos, x; cin >> pos >> x;
            bt.add(pos+1, x);
        }
    }

    return 0;
}
