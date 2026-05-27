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

const int MAXN = 1e7 + 10;

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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi arr(n); rep(i, 0, n) cin >> arr[i];
        
        bit<int> bt(MAXN);

        ll inv = 0;
        for(int i = n-1; i>= 0; i--){
            inv += bt.query(arr[i]-1);
            bt.add(arr[i],1);
        }

        cout << inv << endl;

    }

    return 0;
}