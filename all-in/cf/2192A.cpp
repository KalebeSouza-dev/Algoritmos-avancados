#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    string s; cin >> s;

    set<char> ss(all(s));
    int blocos = 1;
    bool bloco_len2_meio = false;
    for (int i = 0; i < n-1; i++){
        if (s[i] != s[i+1]) blocos++;
        if (s[i] == s[i+1]){
            bloco_len2_meio = true;
        }
    }

    if (s[0] == s[n-1]) cout << blocos << endl;
    else if (bloco_len2_meio) cout << blocos + 1 << endl;
    else cout << blocos << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}