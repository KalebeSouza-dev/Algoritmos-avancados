#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, d; cin >> n >> m >> d;

    vector<int> c(m), out(n+2, 0);

    for (int i = 0; i < m; i++) cin >> c[i];
    
    int pos = n;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < c[i]; j++) {
            out[pos] = i + 1;
            pos--;
        }
    }

    ll sum = 0;
    for (auto x : c) sum += x;

    if (sum + (m + 1) * (d - 1) < n) {
        cout << "NO\n";
        return 0;
    }

    int rpos = pos + 1 , lpos = d;
    //for(int i = 1; i <= n; i++) cout << out[i] << " ";

    while (rpos <= n) {
        while (rpos <= n && out[rpos] == 0) rpos++;
        if (rpos > n) break;

        int x = out[rpos];

        int len = 0;
        while (rpos + len <= n && out[rpos + len] == x) len++;

        while (lpos <= n && out[lpos] != 0) lpos++;
        if (lpos > n) break;

        for (int k = 0; k < len; k++) {
            out[lpos + k] = x;
            out[rpos + k] = 0;
        }
        lpos += len;
        rpos += len;

        lpos += d - 1;
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << out[i] << " ";
    cout << endl;

    return 0;
}