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

// String Hashing
//
// Complexidades:
// construtor - O(|s|)
// operator() - O(1)

const ll MOD = (1e9 + 7);

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|


int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s1; cin >> s1;
    string s2 = s1; reverse(all(s2));
    int n = sz(s1);

    str_hash<MOD> h1(s1), h2(s2);

    auto is_pal = [&](int l, int r) {
        int rl = n - 1 - r;
        int rr = n - 1 - l;

        return h1(l, r) == h2(rl, rr);
    };

    int best_len = 1, best_l = 0;

    //impar
    for (int c = 0; c < n; c++){
        int l = 0, r = min(c, n - 1 - c);
        int ans = 0;

        while (l <= r){
            int mid = (l + r) / 2;

            int ll = c - mid, rr = c + mid;

            if (is_pal(ll, rr)){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        int len = 2 * ans + 1;
        if (len > best_len){
            best_len = len;
            best_l = c - ans;
        }
    }

    //par
    for (int c = 0; c < n-1; c++){
        int l = 0, r = min(c, n - 2 - c);
        int ans = -1;

        while (l <= r){
            int mid = (l + r) / 2;

            int ll = c - mid, rr = c + mid + 1;

            if (is_pal(ll, rr)){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        if (ans != -1) {
            int len = 2 * (ans + 1);

            if (len > best_len) {
                best_len = len;
                best_l = c - ans;
            }
        }
    }

    for (int i = best_l; i < best_l+best_len; i++){
        cout << s1[i];
    }
    cout << endl;

    return 0;
}

//maldito talento