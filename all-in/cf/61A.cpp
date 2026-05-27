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
        return query(r) - query(l - 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vi arr(n); rep(i, 0, n) cin >> arr[i];

    //compressao de coords
    vi compressao = arr;
    sort(all(compressao));
    for (auto &x : arr){
        x = lower_bound(all(compressao), x) - compressao.begin() + 1;
    }

    vi leftGrande(n), rightPequeno(n);
    ll ans = 0;

    bit<ll> bt(n);
    for (int i = 0; i < n; i++){
        leftGrande[i] = i - bt.query(arr[i]);
        
        bt.add(arr[i], 1);
    }
    
    bit<ll> bt2(n);
    for (int i = n-1; i >= 0; i--){
        rightPequeno[i] = bt2.query(arr[i]);
        
        bt2.add(arr[i], 1);
    }

    for(int i = 0; i < n; i++){
        ans += 1LL * leftGrande[i] * rightPequeno[i];
    }

    cout << ans << endl;

    return 0;
}

//maldito talento