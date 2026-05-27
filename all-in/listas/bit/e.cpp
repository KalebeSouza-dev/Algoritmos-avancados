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
        return query(r) - query(l-1);
    }
    T find_kth(T k) {
        T pos = 0;

        int LOG = 0;
        while ((1 << (LOG + 1)) <= n) LOG++;

        for (int i = 1 << LOG; i > 0; i >>= 1) {
            if (pos + i <= n && a[pos + i] < k) {
                k -= a[pos + i];
                pos += i;
            }
        }
        return pos + 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vi a(n/2), b(n/2);
    rep(i, 0, n/2) cin >> a[i];
    rep(i, 0, n/2) cin >> b[i];

    bit<ll> bt(n);
    for (int i = 1; i <= n; i++) {bt.add(i, 1);}

    vi outA, outB;
    rep(i, 0, n/2){
        int p1 = bt.find_kth(a[i]);
        outA.pb(p1);
        bt.add(p1, -1);

        int p2 = bt.find_kth(b[i]);
        outB.pb(p2);
        bt.add(p2, -1);
    }

    for(auto x : outA) cout << x << " "; cout << endl;
    for(auto x : outB) cout << x << " "; cout << endl;


    return 0;
}

//maldito talento