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

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

void solve_tc(){
    int n; cin >> n;
    string s; cin >> s;
    
    if (n == 1 && s[0] == '0') {cout << 1 << endl; return;}

    int ans = count(all(s), '1');

    for(int i =0; i < n; i++) {
        int j = i;
        if(s[i] == '1') continue;
        while(j < n && s[j] == '0') j++;
 
        int len = j - i;
        if(i > 0) len--;
        if(j != n) len--;
 
        i = j - 1;
        if(len > 0)
            ans += (len + 2) / 3;
    
    }
    //cout << s << endl;
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

// :(  //