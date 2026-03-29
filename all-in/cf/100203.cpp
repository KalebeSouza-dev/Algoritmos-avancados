#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    int idx = 1;
    while(n--){
        cout << "Case " << idx++ << ": ";
        
        string s, t; cin >> s >> t;

        //cout << count(all(s), '0') << " " <<  count(all(t), '0') << endl;
        int s1 = count(all(s), '1'), t1 = count(all(t), '1');
        if (s1 > t1) {cout << -1 << endl; continue;}
        //cout << "passou";

        int diff0 = 0, diff1 = 0, q = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {q++;continue;}
            if (s[i] == '0' && t[i] == '1') diff0++;
            else if (s[i] == '1' && t[i] == '0') diff1++;
        }

        int swaps = min(diff0, diff1);
        diff0 -= swaps;
        diff1 -= swaps;
        
        if (diff1 > q) {cout << -1 << endl;continue;}
        
        
        int ans = swaps + 2 * diff1 + diff0;
        q -= diff1;
        
        cout << ans + q << endl;
    }

    return 0;
}
