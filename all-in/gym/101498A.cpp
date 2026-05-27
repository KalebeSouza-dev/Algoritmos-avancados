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

void solve_tc(){
    int n; cin >> n;
    map<int, int> freq;

    string s; int k;
    while(n--){
        cin >> s >> k;
        freq[k]++;
    }
    pii ans = {0, 0};
    for(auto [k, v] : freq){
        if (v  > ans.second) {
            ans.second = v;
            ans.first = k;
        }
        if (v == ans.second) {
            ans.first = min(ans.first, k);
        }
    }

    cout << ans.first << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento