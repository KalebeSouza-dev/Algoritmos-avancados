#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
        int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26);
    for(int i = 0; i < n; i++) cnt[s[i] - 'a']++;
 
    string ans = "";
    int last = -1;
    for(int i = 0; i < n; i++) {
        int cur = -1;
        for(int j = 0; j < 26; j++) if (cnt[j]) {
            if (last != j) {
                if (cur == -1 || cnt[cur] < cnt[j]) {
                    cur = j;
                }
            }
        }
        if (cur == -1) cur = last;
        cnt[cur]--;
        last = cur;
        ans += 'a' + cur;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}