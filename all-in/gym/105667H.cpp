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
    map<string, int> mp;
    string s; 
    while(n--){
        cin >> s;
        mp[s]++;
    }

    string win;
    int mx = 0;

    for (auto [k, v] : mp){
        if (v > mx){
            mx = v;
            win = k;
        }
    }

    cout << win << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1;
    while(tc--) solve_tc();
    
    return 0;
}