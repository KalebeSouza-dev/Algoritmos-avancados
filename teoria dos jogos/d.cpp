#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    string s; cin >> s;
    for (int i = 0; i < (int) s.size(); i++){
        if (i % 2 == 0) {
            if (s[i] == 'a') cout << 'b';
            else cout << 'a';
        } else {
            if (s[i] == 'z') cout << 'y';
            else cout << 'z'; 
        }
    }

    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}