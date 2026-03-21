#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void yes(){cout << "YES\n";}
void no(){cout << "NO\n";}


void solve_tc(){
    // traduzi errado
    int n; cin >> n;
    string s; cin >> s;

    if (s[0] == '1' || s[n-1] == '1') {
        yes();
        return;
    }
        
    for (int i = 0; i < n - 1; i++){
        if (s[i] == '1' && s[i+1] == '1'){
            yes();
            return;
        }
    }
    
    no();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}