#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

bool check(const vector<int>& pos, int d) {
    for(int i = 1; i < pos.size(); i++) {
        if(pos[i] - pos[i-1] > d) return false;
    }
    return true;
}

void solve_tc(){
    //cout << "CASE\n";
    string s; cin >> s;

    vector<int> out = {0};
    int n = sz(s);
    for (int i = 0; i <= sz(s); i++){
        if (s[i] == 'R'){
            out.push_back(i+1);
        }
    }
    out.push_back(n+1);

    int l = 1, r = n + 1;
    int ans = n + 1;

    while (l <= r){
        int mid = (l + r) / 2;
        if (check(out, mid)) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }

    // for (int i = 0; i < (int) out.size() - 1; i++){
    //     ans = max(ans, out[i+1]-out[i]);
    // }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}