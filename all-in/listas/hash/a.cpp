#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).rbegin(), (x).rend()
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

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s1, s2; cin >> s1 >> s2;

    str_hash<MOD> hs1(s1), hs2(s2);  

    int m = sz(s2);
    int ans = 0;
    for(int i = 0; i + m - 1 < sz(s1); i++){
        if (hs1(i, i + m - 1) == hs2(0, m-1)) ans++;
    }
    
    cout << ans << endl;

    return 0;
}

// maldito talento