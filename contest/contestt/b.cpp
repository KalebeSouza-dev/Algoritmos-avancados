#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    string s; cin >> s;
    s = s + s;
    int ans = 0;
    for (int i = 0; i < 2 * n; i ++){
        if (s[i] == '0'){
            int idx = i;
            int j = 0;
            while(idx < 2*n -1 && s[idx] == '0'){
                j++;
                idx++;
            }
            i = idx;
            ans = max(ans, j);
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}