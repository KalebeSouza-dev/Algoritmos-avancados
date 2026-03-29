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

    string sorted = s;
    sort(all(sorted));

    if (s == sorted){cout << "Bob\n"; return;}

    cout << "Alice\n";
    vector<int> idx;
    for(int i = 0; i < n; ++i) {
        if(s[i] != sorted[i]) {
            idx.push_back(i);
        }
    }

    cout << idx.size() << '\n';

    for(auto i : idx) cout << i+1 << " ";
    cout << '\n';

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}