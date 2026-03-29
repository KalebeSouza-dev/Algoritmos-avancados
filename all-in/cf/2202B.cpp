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

    if (n % 2 == 1 && s[0] == 'b') {cout << "NO\n"; return;}
    else if(n % 2 == 0){
        for(int i = 0; i < n-1; i += 2){
            if(s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]){
                cout << "NO\n"; return;
            }
        }
    } else{
        for(int i = 1; i < n-1; i += 2){
            if(s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]){
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n"; return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}